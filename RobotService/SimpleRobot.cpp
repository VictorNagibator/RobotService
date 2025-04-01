#include "SimpleRobot.h"

void SimpleRobot::startDelivery(const std::string& destination)
{
    try
    {
        std::cout << "������� ����� " << robotID << " (" << modelName
            << ") �������� �������� �� " << destination << ".\n";
        moveTo(destination);
        communication->sendData("������� �����: ����� ��������.");
    }
    catch (const std::exception& e)
    {
        std::cout << "������� ����� " << robotID << " (" << modelName
            << ") �� ����� ����������� ��������: "
            << e.what() << "\n";
    }
}

void SimpleRobot::stopDelivery() 
{
    std::cout << "������� ����� " << robotID << " (" << modelName
        << ") ��������� ��������.\n";
    engine->stop();
    communication->sendData("������� �����: ��������� ��������.");
}

void SimpleRobot::checkStatus()
{
    std::cout << "������� ����� " << robotID
        << ": ����� " << powerSource->getCharge()
        << "%.\n";
}

void SimpleRobot::moveTo(const std::string& destination)
{
    engine->start();
    powerSource->consume(30); //��� ������� ������ �����-�� ���������� ������� ��� �������
	navigation->navigate(destination);
}