#pragma once

//Прототип робота
class IPrototypeRobot
{
public:
	virtual IPrototypeRobot* clone() const = 0;
};