#include "Drone.h"

void Drone::checkStatus()
{
    std::cout << "���� " << robotID
        << ": ����� " << powerSource->getCharge()
        << "%.\n";
}

void Drone::moveTo(const std::string& destination)
{
    powerSource->consume(30); //��� ������� ������ �����-�� ���������� ������� ��� �������
	navigation->navigate(destination);
}

Drone* Drone::clone() const
{
    //������� ��������� ��� ���������� ������, � ����� ������ ������� ������
	return new Drone
    (
        robotID,
        modelName,
		engine->clone(),
		navigation->clone(),
		communication->clone(),
		powerSource->clone()
    );
}