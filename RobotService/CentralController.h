#pragma once
#include "IController.h"
#include "MyList.h"

//Центральный контроллер, распределяющий задания и мониторящий роботов
class CentralController : public IController {
private:
	IAggregate<IRobot*>* robots; //Коллекция роботов
	static CentralController* self; //Единственный экземпляр контроллера

	//Приватный конструктор, чтобы предотвратить создание нескольких экземпляров контроллера
    CentralController(const std::string& name, IAggregate<IRobot*>* collection)
        : IController(name), robots(collection) {
    }

	//Удаляем копирующий конструктор и оператор присваивания
	//чтобы предотвратить создание нескольких экземпляров контроллера
    CentralController(const CentralController& root) = delete;
    CentralController& operator=(const CentralController&) = delete;
public:
	//Статический метод для получения единственного экземпляра контроллера
	static CentralController* getInstance(
		const std::string& name = "Главный контроллер",
		IAggregate<IRobot*>* collection = new MyList<IRobot*>()
	);

	//Метод для сохранения состояния контроллера
	ControllerSnapshot* saveState() override;
	//Метод для восстановления состояния контроллера
	void restoreState(ControllerSnapshot* m) override;

	//Остальные методы оставляем такими же
    void addRobot(IRobot* robot) override;
	void removeRobot(IRobot* robot) override;
    void dispatchDelivery(IRobot* robot, const std::string& destination) override;
    void monitorRobots() const override;

    const IAggregate<IRobot*>& getRobots() const override;
};