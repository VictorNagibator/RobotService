#pragma once
#include "IEngine.h"
#include "IPowerSource.h"
#include "ICommunication.h"
#include "INavigation.h"
#include "Prototype.h"
#include "ISubject.h"
#include "IAggregate.h"
#include "IVendingMachine.h"

class IRobotState; //Объявляем класс, так как иначе происходит циклический include

//Интерфейс робота
class IRobot : public Prototype, public ISubject {
protected:
    int robotID; //Уникальный номер робота
    std::string modelName; //Название модели
    IEngine* engine;
    INavigation* navigation;
    ICommunication* communication;
    IPowerSource* powerSource;

	IRobotState* state; //Состояние робота (например, "доставляет", "ожидает", "в пути" и т.д.)

	IAggregate<IObserver*>* observers; //Наблюдатели, которые следят за состоянием робота
	std::string message; //Сообщение для наблюдателей

	virtual void changeState(IRobotState* s); //Сменить состояние робота
public:
    IRobot(int id, const std::string& model, IEngine* engine,
        INavigation* nav, ICommunication* comm, IPowerSource* power);

    virtual ~IRobot();

    //Выполнить действие
    virtual void execute();

    //Методы для смены состояния
    virtual void startDelivery(const std::string& destination, const std::string& machineLocation = nullptr,
        int itemID = -1,
        IVendingMachine* vendingMachine = nullptr); 
    virtual void startCharging();
    virtual void runDiagnostics();
    virtual void wait();

    virtual void checkStatus() = 0; //Узнать состояние робота

	virtual void moveTo(const std::string& destination) = 0; //Переместиться в точку назначения

    //Стандартные геттеры
	virtual int getRobotID() const;
	virtual std::string getModelName() const;
	virtual IEngine* getEngine() const;
	virtual INavigation* getNavigation() const;
	virtual ICommunication* getCommunication() const;
	virtual IPowerSource* getPowerSource() const;

    virtual IRobot* clone() const = 0;

	//Методы для работы с наблюдателями
	virtual void attach(IObserver* observer) override; //Добавить наблюдателя
	virtual void detach(IObserver* observer) override; //Удалить наблюдателя
	virtual void notify() override; //Уведомить наблюдателей

	virtual void setMessage(const std::string& msg); //Установить сообщение для наблюдателей
};