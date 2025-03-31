#pragma once
#include "IController.h"

class RobotManager
{
private:
	IController* controller; //Контроллер для управления роботами

    const std::string baseLocation = "Кутузова, 61"; //Например, адрес общей базы всех роботов
	const std::string chargeLocation = "Кутузова, 62"; //Адрес пункта подзарядки
public:
    RobotManager(IController* ctrl);

    //Возвращает всех роботов на базу
    void returnAllRobotsToBase();
    //Аварийная остановка всех роботов
    void emergencyStopAllRobots();
    //Обновляет маршруты для всех роботов
    void updateRoutesForAll(const std::string& newRoute);
    //Отправляет роботов с низким зарядом на подзарядку
    void sendLowBatteryRobotsToCharge(double minBatteryLevel = 20.0);

    //Возможность узнать, сколько роботов способны доставлять заказы
	int getSuitableRobotsCount() const;
};