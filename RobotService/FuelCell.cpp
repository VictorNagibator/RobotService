#include "FuelCell.h"

FuelCell::FuelCell(FuelType fuelType, int capacity, IEnvironment* environment)
{
    this->fuelType = fuelType;
    this->capacity = capacity;
    this->environment = environment;
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

    std::cout << "������� ������������. ������� �������: " << fuelLevel << " / " << capacity << ".\n";
}