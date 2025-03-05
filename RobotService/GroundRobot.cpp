#include "GroundRobot.h"

void GroundRobot::startDelivery(const std::string& destination)
{
    std::cout << "�������� ����� " << robotID << " (" << modelName
        << ") �������� �������� �� " << destination << ".\n";
    engine->start();
    navigation->navigate(destination);
    communication->sendData("�������� �����: ����� ��������.");
}

void GroundRobot::stopDelivery() 
{
    std::cout << "�������� ����� " << robotID << " (" << modelName
        << ") ��������� ��������.\n";
    engine->stop();
    communication->sendData("�������� �����: ��������� ��������.");
}

void GroundRobot::updateStatus()
{
    std::cout << "�������� ����� " << robotID
        << ": ����� " << powerSource->getCharge()
        << "%.\n";
}