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
    robots->push(robot);
    std::cout << controllerName << ": робот добавлен.\n";
}

void CentralController::dispatchDelivery(IRobot* robot, const std::string& destination)
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

    std::cout << controllerName << ": назначение доставки до " << destination << "\n";
    robot->startDelivery(destination);

    //В дальнейшем можно будет добавить логику ожидания, контроля процесса доставки и т.д.

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

	controllerName = IController::getName(m); //Восстанавливаем имя контроллера
	robots = IController::getRobots(m); //Восстанавливаем коллекцию из снимка
}