#pragma once
#include "IRobotExpert.h"
#include "Iterator.h"

class BasicRobotExpert : public IRobotExpert {
private:
    double maxSafeTemperatureForEngine = 90.0; //Максимальный порог температуры двигателя
	double minBatteryLevel = 20.0; //Минимальный заряд батареи

	//Максимальная температура для доставки (90% от максимальной; мы не хотим, чтобы робот во время доставки сломался)
	const double maxTemperatureForDelivery = maxSafeTemperatureForEngine * 0.9; 
	//Аналогично для заряда батареи
	const double minBatteryLevelForDelivery = minBatteryLevel * 1.1;
public:
	BasicRobotExpert(IController* ctrl) : IRobotExpert(ctrl) {} //Можно оставить значения по умолчанию
	BasicRobotExpert(IController* ctrl, double maxSafeTemperatureForEngine, double minBatteryLevel); //А можно задать свои

	//Возвращает количество роботов, готовых к выполнению заказа
	int countSuitableRobots() const override;

	//Возвращает количество роботов, нуждающихся в срочном обслуживании
	int countRobotsInNeedOfService() const override;
};