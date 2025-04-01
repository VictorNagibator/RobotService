#pragma once
#include "IPowerSource.h"

class Battery : public IPowerSource {
private:
    int capacity; //������� ������� � ���
    double currentCharge = 0; //������� ����� � ���
public:
    Battery(int capacity, IEnvironment* environment);

    //���������� ���������� ����� � ���������.
    double getCharge() const override;
    //�������������� �� ������� ������.
    void recharge() override;
    //������ ������� �� ����������� ���������� ���
    void consume(double usage) override;
};
