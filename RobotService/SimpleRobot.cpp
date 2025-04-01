#include "SimpleRobot.h"

void SimpleRobot::startDelivery(const std::string& destination)
{
    try
    {
        std::cout << "Обычный робот " << robotID << " (" << modelName
            << ") начинает доставку до " << destination << ".\n";
        moveTo(destination);
        communication->sendData("Обычный робот: начал доставку.");
    }
    catch (const std::exception& e)
    {
        std::cout << "Обычный робот " << robotID << " (" << modelName
            << ") не может осуществить доставку: "
            << e.what() << "\n";
    }
}

void SimpleRobot::stopDelivery() 
{
    std::cout << "Обычный робот " << robotID << " (" << modelName
        << ") прекратил доставку.\n";
    engine->stop();
    communication->sendData("Обычный робот: прекратил доставку.");
}

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