#pragma once
#include "IPowerSource.h"
#include "FuelType.h"

class FuelCell : public IPowerSource {
private:
    FuelType fuelType; //��� ������� (��������, ������ ��� 95)
    double fuelLevel; //������� ������� �������
    int capacity; //����������� ���������� ����
public:
    FuelCell(FuelType fuelType, int capacity);

    //���������� ������� ������� �������
    double getCharge() const override;

    //���������� ��������� ������� �� 100%
    void recharge() override;

    //��������� ������� �������.
    void consume(double amount) override;
};

