#include "Drone.h"

void Drone::startDelivery(const std::string& destination)
{
    std::cout << "���� " << robotID << " (" << modelName
        << ") �������� � �������� �������� �� " << destination << ".\n";
    engine->start();
    navigation->navigate(destination);
    communication->sendData("����: ����� ��������.");
}

void Drone::stopDelivery()
{
    std::cout << "���� " << robotID << " (" << modelName
        << ") ������������ � ����������� ��������.\n";
    engine->stop();
    communication->sendData("����: ��������� ��������.");
}

void Drone::updateStatus()
{
    std::cout << "���� " << robotID
        << ": ����� " << powerSource->getCharge()
        << "%, ���������� ���������.\n";
}