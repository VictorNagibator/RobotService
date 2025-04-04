#pragma once
#include "IController.h"

//Интерфейс информационного эксперта по состоянию роботов
class IRobotExpert {
protected:
	IController* controller; //Контроллер, с которым работает эксперт
public:
	IRobotExpert(IController* controller) : controller(controller) {} //Конструктор с указанием контроллера

    //Возвращает количество роботов, готовых к выполнению заказа
    virtual int countSuitableRobots() const = 0;

	//Возвращает количество роботов, нуждающихся в срочном обслуживании
	virtual int countRobotsInNeedOfService() const = 0;
};