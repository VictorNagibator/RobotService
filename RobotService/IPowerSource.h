#pragma once
#include <string>
#include <iostream>
#include "IEnvironment.h"

class IPowerSource {
protected:
    IEnvironment* environment;
public:
    //Возвращает текущий уровень заряда (в процентах)
    virtual double getCharge() const = 0;

    //Восполнение заряда (перезарядка/заправка)
    virtual void recharge() = 0;

    //Трата заряда
    virtual void consume(double usage) = 0;

    //Можно поменять среду
    virtual void setEnvironment(IEnvironment* env);
};