#include "Drone.h"

void Drone::startDelivery(const std::string& destination)
{
    try
    {
        engine->start();
        powerSource->consume(30); //��� ������� ������ �����-�� ���������� ������� ��� �������
        std::cout << "���� " << robotID << " (" << modelName
            << ") �������� � �������� �������� �� " << destination << ".\n";
        navigation->navigate(destination);
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