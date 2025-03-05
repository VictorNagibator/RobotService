#include "GroundRobot.h"

void GroundRobot::startDelivery(const std::string& destination)
{
    std::cout << "Наземный робот " << robotID << " (" << modelName
        << ") начинает доставку до " << destination << ".\n";
    engine->start();
    navigation->navigate(destination);
    communication->sendData("Наземный робот: начал доставку.");
}

void GroundRobot::stopDelivery() 
{
    std::cout << "Наземный робот " << robotID << " (" << modelName
        << ") прекратил доставку.\n";
    engine->stop();
    communication->sendData("Наземный робот: прекратил доставку.");
}

void GroundRobot::updateStatus()
{
    std::cout << "Наземный робот " << robotID
        << ": заряд " << powerSource->getCharge()
        << "%.\n";
}