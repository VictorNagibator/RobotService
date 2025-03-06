#include "GroundRobot.h"

void GroundRobot::startDelivery(const std::string& destination)
{
    try
    {
        engine->start();
        powerSource->consume(30); //��� ������� ������ �����-�� ���������� ������� ��� �������
        std::cout << "�������� ����� " << robotID << " (" << modelName
            << ") �������� �������� �� " << destination << ".\n";
        navigation->navigate(destination);
        communication->sendData("�������� �����: ����� ��������.");
    }
    catch (const std::exception& e)
    {
        std::cout << "�������� ����� " << robotID << " (" << modelName
            << ") �� ����� ����������� ��������: "
            << e.what() << "\n";
    }
}

void GroundRobot::stopDelivery() 
{
    std::cout << "�������� ����� " << robotID << " (" << modelName
        << ") ��������� ��������.\n";
    engine->stop();
    communication->sendData("�������� �����: ��������� ��������.");
}

void GroundRobot::checkStatus()
{
    std::cout << "�������� ����� " << robotID
        << ": ����� " << powerSource->getCharge()
        << "%.\n";
}