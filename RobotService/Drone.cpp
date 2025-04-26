#include "Drone.h"

void Drone::checkStatus()
{
    std::cout << "Дрон " << robotID
        << ": заряд " << powerSource->getCharge()
        << "%.\n";
}

void Drone::moveTo(const std::string& destination)
{
    powerSource->consume(30); //Для примера тратим какое-то количество топлива или энергии
	navigation->navigate(destination);
}

Drone* Drone::clone() const
{
    //Сначала клонируем все компоненты робота, а потом только создаем нового
	return new Drone
    (
        robotID,
        modelName,
		engine->clone(),
		navigation->clone(),
		communication->clone(),
		powerSource->clone()
    );
}