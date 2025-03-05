#pragma once
#include <string>
#include <iostream>

class IPowerSource {
public:
    //���������� ������� ������� ������ (� ���������)
    virtual double getCharge() const = 0;

    //����������� ������ (�����������/��������)
    virtual void recharge() = 0;

    //����� ������
    virtual void consume(double usage) = 0;
};