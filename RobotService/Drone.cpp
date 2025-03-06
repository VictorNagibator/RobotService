#include "Drone.h"

void Drone::startDelivery(const std::string& destination)
{
    try
    {
        engine->start();
        powerSource->consume(30); //Для примера тратим какое-то количество топлива или энергии
        std::cout << "Дрон " << robotID << " (" << modelName
            << ") взлетает и начинает доставку до " << destination << ".\n";
        navigation->navigate(destination);
        communication->sendData("Дрон: начал доставку.");
    }
    catch (const std::exception& e)
    {
		std::cout << "Дрон " << robotID << " (" << modelName
			<< ") не может осуществить доставку: "
            << e.what() << "\n";
    }
}

void Drone::stopDelivery()
{
    std::cout << "Дрон " << robotID << " (" << modelName
        << ") приземляется и заканчивает доставку.\n";
    engine->stop();
    communication->sendData("Дрон: прекратил доставку.");
}

void Drone::checkStatus()
{
    std::cout << "Дрон " << robotID
        << ": заряд " << powerSource->getCharge()
        << "%.\n";
}