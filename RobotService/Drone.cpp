#include "Drone.h"

void Drone::startDelivery(const std::string& destination)
{
    std::cout << "Дрон " << robotID << " (" << modelName
        << ") взлетает и начинает доставку до " << destination << ".\n";
    engine->start();
    navigation->navigate(destination);
    communication->sendData("Дрон: начал доставку.");
}

void Drone::stopDelivery()
{
    std::cout << "Дрон " << robotID << " (" << modelName
        << ") приземляется и заканчивает доставку.\n";
    engine->stop();
    communication->sendData("Дрон: прекратил доставку.");
}

void Drone::updateStatus()
{
    std::cout << "Дрон " << robotID
        << ": заряд " << powerSource->getCharge()
        << "%, стабильное состояние.\n";
}