#pragma once
#include "IEngine.h"
#include "IPowerSource.h"
#include "ICommunication.h"
#include "INavigation.h"
#include "Prototype.h"

//Интерфейс робота
class IRobot : public Prototype {
protected:
    int robotID; //Уникальный номер робота
    std::string modelName; //Название модели
    IEngine* engine;
    INavigation* navigation;
    ICommunication* communication;
    IPowerSource* powerSource;
public:
    IRobot(int id, const std::string& model, IEngine* engine,
        INavigation* nav, ICommunication* comm, IPowerSource* power);

    virtual void startDelivery(const std::string& destination) = 0; //Начать доставку
    virtual void stopDelivery() = 0; //Закончить доставку
    virtual void checkStatus() = 0; //Узнать состояние робота

	virtual void moveTo(const std::string& destination) = 0; //Переместиться в точку назначения

    //Стандартные геттеры
	virtual const IEngine& getEngine() const;
	virtual const INavigation& getNavigation() const;
	virtual const ICommunication& getCommunication() const;
	virtual const IPowerSource& getPowerSource() const;

    virtual IRobot* clone() const = 0;
};