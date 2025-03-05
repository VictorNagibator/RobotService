#include "FuelCell.h"

double FuelCell::getCharge() const {
    return fuelLevel;
}

void FuelCell::recharge() {
    fuelLevel = capacity;
    std::cout << "��������� ��� ��������� ���������.\n";
}

void FuelCell::consume(double amount) {
    //�� ����� ���� �������������� ������� � ����
    fuelLevel = (fuelLevel - amount < 0 ? 0 : fuelLevel - amount);

    std::cout << "������� ������������. ������� �������: " << fuelLevel << " / " << capacity << ".\n";
}