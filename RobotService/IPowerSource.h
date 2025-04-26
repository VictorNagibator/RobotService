#pragma once
#include <string>
#include <iostream>
#include "IEnvironment.h"
#include "Prototype.h"
#include "Visitable.h"

class IPowerSource : public Prototype, public Visitable {
protected:
    IEnvironment* environment;
public:
    IPowerSource(IEnvironment* env) : environment(env) {}

    //Возвращает текущий уровень заряда (в процентах)
    virtual double getCharge() const = 0;

    //Восполнение заряда (перезарядка/заправка)
    virtual void recharge() = 0;

    //Трата заряда
    virtual void consume(double usage) = 0;

    IEnvironment* getEnvironment() const;
    //Можно поменять среду
    virtual void setEnvironment(IEnvironment* env);

	virtual IPowerSource* clone() const = 0;

    virtual void accept(IComponentVisitor& v) const override;
};