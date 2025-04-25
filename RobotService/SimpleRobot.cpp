#include "SimpleRobot.h"

void SimpleRobot::checkStatus()
{
    std::cout << "Обычный робот " << robotID
        << ": заряд " << powerSource->getCharge()
        << "%.\n";
}

void SimpleRobot::moveTo(const std::string& destination)
{
    engine->start();
    powerSource->consume(30); //Для примера тратим какое-то количество топлива или энергии
	navigation->navigate(destination);
}

SimpleRobot* SimpleRobot::clone() const
{
	//Сначала клонируем все компоненты робота, а потом только создаем нового
	return new SimpleRobot
	(
		robotID,
		modelName,
		engine->clone(),
		navigation->clone(),
		communication->clone(),
		powerSource->clone()
	);
}