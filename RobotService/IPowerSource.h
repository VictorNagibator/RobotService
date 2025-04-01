#pragma once
#include <string>
#include <iostream>
#include "IEnvironment.h"

class IPowerSource {
protected:
    IEnvironment* environment;
public:
    //���������� ������� ������� ������ (� ���������)
    virtual double getCharge() const = 0;

    //����������� ������ (�����������/��������)
    virtual void recharge() = 0;

    //����� ������
    virtual void consume(double usage) = 0;

    //����� �������� �����
    virtual void setEnvironment(IEnvironment* env);
};