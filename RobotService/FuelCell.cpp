#include "FuelCell.h"

FuelCell::FuelCell(FuelType fuelType, int capacity, IEnvironment* environment) : IPowerSource(environment)
{
    this->fuelType = fuelType;
    this->capacity = capacity;
}

double FuelCell::getCharge() const {
    return fuelLevel;
}

void FuelCell::recharge() {
    fuelLevel = capacity;
    std::cout << "��������� ��� ��������� ���������.\n";
}

void FuelCell::consume(double amount) {
    //�� ����� ���� �������������� ������� � ����
    if (fuelLevel < amount) throw std::exception("������������ �������!");
    fuelLevel -= amount;
    environment->interact();
    std::cout << "������� ������������. ������� �������: " << fuelLevel << " / " << capacity << ".\n";
}

FuelCell* FuelCell::clone() const
{
	return new FuelCell(*this);
}