#pragma once
#include <string>

//Интерфейс среды передвижения
class IEnvironment {
public:
    //Модификатор сопротивления среды (например, трение или сопротивление воды)
    virtual double getResistance() const = 0;
    //Модификатор точности навигации (например, влияние погодных условий)
    virtual double getNavigationAccuracyFactor() const = 0;
    //Коэффициент затухания сигнала для средств связи
    virtual double getCommunicationAttenuation() const = 0;

    //Взаимодействие какое-то со средой
    virtual void interact() = 0;

    //Получить название самой среды
    virtual std::string getEnvironmentName() const = 0;
};