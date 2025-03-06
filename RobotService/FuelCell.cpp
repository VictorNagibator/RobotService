#include "FuelCell.h"

FuelCell::FuelCell(FuelType fuelType, int capacity)
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

    std::cout << "������� ������������. ������� �������: " << fuelLevel << " / " << capacity << ".\n";
}