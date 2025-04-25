#include "SimpleRobot.h"

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