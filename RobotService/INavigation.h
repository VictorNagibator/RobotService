#pragma once
#include <string>
#include "IEnvironment.h"
#include "Prototype.h"
#include "Visitable.h"

//Абстрактный класс навигационной системы
class INavigation : public Prototype, public Visitable {
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
    
    //Проверка системы навигации
	virtual bool selfTest() const = 0;

    //Можно поменять среду
    virtual void setEnvironment(IEnvironment* env);
    IEnvironment* getEnvironment() const;

	//Получить координаты робота
    double getX() const;
    double getY() const;

	virtual INavigation* clone() const = 0;

    virtual void accept(IComponentVisitor& v) const override;
};