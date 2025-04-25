#pragma once
#include "IEngine.h"
#include "IPowerSource.h"
#include "ICommunication.h"
#include "INavigation.h"
#include "Prototype.h"

class IRobotState; //Объявляем класс, так как иначе происходит циклический include

//Интерфейс робота
class IRobot : public Prototype {
protected:
    int robotID; //Уникальный номер робота
    std::string modelName; //Название модели
    IEngine* engine;
    INavigation* navigation;
    ICommunication* communication;
    IPowerSource* powerSource;

	IRobotState* state; //Состояние робота (например, "доставляет", "ожидает", "в пути" и т.д.)

	virtual void changeState(IRobotState* s); //Сменить состояние робота
public:
    IRobot(int id, const std::string& model, IEngine* engine,
        INavigation* nav, ICommunication* comm, IPowerSource* power);

    //Выполнить действие
    virtual void execute();

    //Методы для смены состояния
    virtual void startDelivery(const std::string& destination);
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
};