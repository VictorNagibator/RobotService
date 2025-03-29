#include "GroundRobot.h"

void GroundRobot::startDelivery(const std::string& destination)
{
    try
    {
        std::cout << "Наземный робот " << robotID << " (" << modelName
            << ") начинает доставку до " << destination << ".\n";
        moveTo(destination);
        communication->sendData("Наземный робот: начал доставку.");
    }
    catch (const std::exception& e)
    {
        std::cout << "Наземный робот " << robotID << " (" << modelName
            << ") не может осуществить доставку: "
            << e.what() << "\n";
    }
}

void GroundRobot::stopDelivery() 
{
    std::cout << "Наземный робот " << robotID << " (" << modelName
        << ") прекратил доставку.\n";
    engine->stop();
    communication->sendData("Наземный робот: прекратил доставку.");
}

void GroundRobot::checkStatus()
{
    std::cout << "Наземный робот " << robotID
        << ": заряд " << powerSource->getCharge()
        << "%.\n";
}

void GroundRobot::moveTo(const std::string& destination)
{
    engine->start();
    powerSource->consume(30); //Для примера тратим какое-то количество топлива или энергии
	navigation->navigate(destination);
}