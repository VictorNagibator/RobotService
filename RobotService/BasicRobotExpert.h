#pragma once
#include "IRobotExpert.h"
#include "Iterator.h"

class BasicRobotExpert : public IRobotExpert {
private:
    double maxSafeTemperatureForEngine = 90.0; //Максимальный порог температуры двигателя
	double minBatteryLevel = 20.0; //Минимальный заряд батареи
public:
	BasicRobotExpert() {} //Можно оставить значения по умолчанию
    BasicRobotExpert(double maxSafeTemperatureForEngine, double minBatteryLevel); //А можно задать свои

    //Сама проверка готовности робота к заказу
    bool isRobotSuitable(IRobot* robot) const override;

	//Фильтрует роботов в агрегате и возвращает тех, кто готов к осуществлению доставки
    MyList<IRobot*> filterSuitableRobots(const IAggregate<IRobot*>& allRobots) const override;
};