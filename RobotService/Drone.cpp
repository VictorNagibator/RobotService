#include "Drone.h"

void Drone::startDelivery(const std::string& destination)
{
    try
    {
        std::cout << "���� " << robotID << " (" << modelName
            << ") �������� � �������� �������� �� " << destination << ".\n";
        moveTo(destination);
        communication->sendData("����: ����� ��������.");
    }
    catch (const std::exception& e)
    {
		std::cout << "���� " << robotID << " (" << modelName
			<< ") �� ����� ����������� ��������: "
            << e.what() << "\n";
    }
}

void Drone::stopDelivery()
{
    std::cout << "���� " << robotID << " (" << modelName
        << ") ������������ � ����������� ��������.\n";
    engine->stop();
    communication->sendData("����: ��������� ��������.");
}

void Drone::checkStatus()
{
    std::cout << "���� " << robotID
        << ": ����� " << powerSource->getCharge()
        << "%.\n";
}

void Drone::moveTo(const std::string& destination)
{
    engine->start();
    powerSource->consume(30); //��� ������� ������ �����-�� ���������� ������� ��� �������
	navigation->navigate(destination);
}