#pragma once
#include "IRobot.h"
#include "MyList.h"

//Интерфейс информационного эксперта по состоянию роботов
class IRobotExpert {
public:
    //Возвращает true, если робот готов к выполнению заказа
    virtual bool isRobotSuitable(IRobot* robot) const = 0;

    //Возвращает список роботов, готовых к выполнению заказа
    virtual MyList<IRobot*> filterSuitableRobots(const IAggregate<IRobot*>& allRobots) const = 0;
};