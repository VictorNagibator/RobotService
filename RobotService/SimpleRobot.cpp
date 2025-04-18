#include "SimpleRobot.h"

void SimpleRobot::startDelivery(const std::string& destination)
{
    try
    {
        communication->establishConnection();
        std::cout << "������� ����� " << robotID << " (" << modelName
            << ") �������� �������� �� " << destination << ".\n";
        moveTo(destination);
        communication->sendData("������� �����: ����� ��������.");
    }
    catch (const std::exception& e)
    {
        stopDelivery();

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
	communication->disconnect();
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

SimpleRobot* SimpleRobot::clone() const
{
	//������� ��������� ��� ���������� ������, � ����� ������ ������� ������
	return new SimpleRobot
	(
		robotID,
		modelName,
		engine->clone(),
		navigation->clone(),
		communication->clone(),
		powerSource->clone()
	);
}