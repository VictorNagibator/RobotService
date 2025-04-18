#pragma once
#include <string>
#include <iostream>
#include "IEnvironment.h"
#include "Prototype.h"

class IPowerSource : public Prototype {
protected:
    IEnvironment* environment;
public:
    IPowerSource(IEnvironment* env) : environment(env) {}

    //���������� ������� ������� ������ (� ���������)
    virtual double getCharge() const = 0;

    //����������� ������ (�����������/��������)
    virtual void recharge() = 0;

    //����� ������
    virtual void consume(double usage) = 0;

    IEnvironment* getEnvironment() const;
    //����� �������� �����
    virtual void setEnvironment(IEnvironment* env);

	virtual IPowerSource* clone() const = 0;
};