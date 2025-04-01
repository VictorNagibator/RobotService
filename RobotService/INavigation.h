#pragma once
#include <string>
#include "IEnvironment.h"

//Абстрактный класс навигационной системы
class INavigation {
protected:
    IEnvironment* environment;

    double x, y; //Координаты робота
public:
    INavigation(IEnvironment* environment, double startX = 0, double startY = 0);

    //Навигация по маршруту к заданной точке
    virtual void navigate(const std::string& destination) = 0;
    //Обновление координат робота
    virtual void updatePosition(double newX, double newY);
    //Коррекция маршрута при возникновении препятствий
    virtual void adjustRoute() = 0;

    //Можно поменять среду
    virtual void setEnvironment(IEnvironment* env);
    IEnvironment* getEnvironment() const;
};