#pragma once
#include <iostream>

class IRobot; //Объявляем класс, так как иначе происходит циклический include

//Интерфейс состояния робота
class IRobotState {
protected:
	IRobot* robot; //Указатель на робота, которому принадлежит состояние
public:
	IRobotState(IRobot* robot) : robot(robot) {} //Конструктор, принимающий указатель на робота

	virtual void enter() = 0; //Вход в состояние
	virtual void execute() = 0; //Выполнение действий в состоянии
	virtual void exit() = 0; //Выход из состояния
	virtual std::string name() const = 0; //Получение имени состояния
};