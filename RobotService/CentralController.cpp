#include "CentralController.h"
#include "ProxyIterator.h"

//Определяем статическую переменную
CentralController* CentralController::self = nullptr;

CentralController* CentralController::getInstance(const std::string& name, IAggregate<IRobot*>* collection) 
{
	//Проверяем, существует ли уже экземпляр контроллера
    if (!self) {
		self = new CentralController(name, collection); //Если нет, создаем новый
    }
	return self; //Возвращаем единственный экземпляр
}

void CentralController::addRobot(IRobot* robot)
{
	robot->attach(this); //Добавляем контроллер как наблюдателя к роботу
    robots->push(robot);
    std::cout << controllerName << ": робот добавлен.\n";
}

void CentralController::dispatchDelivery(
    const std::string& destination,
    IRobot* robot,
    const std::string& machineLocation,
    int itemID,
    IVendingMachine* vendingMachine
)
{
	//Можно назначать доставку только зарегистрированным роботам
	bool isRobotInCollection = false;
    //Получаем прокси итератор на коллекцию роботов
    auto it = ProxyIterator<IRobot*>(robots->begin());
    while (it.hasNext()) {
        if (*(it.next()) == robot) {
            isRobotInCollection = true;
            break;
        }
    }
    if (!isRobotInCollection) throw std::invalid_argument("Робот не зарегистрирован в системе!");

    robot->startDelivery(destination, machineLocation, itemID, vendingMachine);
    
    robot->execute(); //В дальнейшем можно будет добавить логику ожидания, контроля процесса доставки и т.д.

    robot->wait();
}

void CentralController::monitorRobots() const
{
    std::cout << controllerName << ": проверяем состояние роботов...\n";
    //Получаем прокси итератор на коллекцию роботов для автоматического удаления
    auto it = ProxyIterator<IRobot*>(robots->begin());
    while (it.hasNext()) {
        IRobot* currentRobot = *(it.next());
        //Вызываем обновление состояния для каждого робота
        currentRobot->checkStatus();
    }
}

void CentralController::removeRobot(IRobot* robot)
{
	//Удаляем контроллер как наблюдателя у робота
	robot->detach(this);
	std::cout << controllerName << ": удаление робота из системы...\n";
	//Удаляем робота из коллекции
	robots->remove(robot);
}

const IAggregate<IRobot*>& CentralController::getRobots() const
{
    return *robots;
}

ControllerSnapshot* CentralController::saveState()
{
	std::cout << controllerName << ": сохранение состояния контроллера...\n";

	//Создаем копию коллекции роботов
	MyList<IRobot*>* robotsCopy = new MyList<IRobot*>();

    auto it = ProxyIterator<IRobot*>(robots->begin());
    while (it.hasNext()) {
        IRobot* currentRobot = *(it.next());
		robotsCopy->push(currentRobot->clone()); //Копируем робота через прототипа
    }

	return IController::makeSnapshot(controllerName, robotsCopy); //Создаем снимок состояния контроллера
}

void CentralController::restoreState(ControllerSnapshot* m)
{
	std::cout << controllerName << ": восстановление состояния контроллера...\n";
	//Удаляем старую коллекцию роботов
	delete robots;

	controllerName = IController::getNameFromSnapshot(m); //Восстанавливаем имя контроллера
	robots = IController::getRobotsFromSnapshot(m); //Восстанавливаем коллекцию из снимка
}