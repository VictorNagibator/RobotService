#pragma once
#include "IEngine.h"

//����������������
class ElectricMotor : public IEngine {
private:
    const int RPMonInitial = maxRPM * 0.9; //������� ������������� ��� ������ - ����������� ����� ����� �������
public:
    ElectricMotor(const std::string& name, int maxRPM, int temperatureThreshold, IEnvironment* environment)
        : IEngine(name, maxRPM, temperatureThreshold, environment) {}

    void start() override;
    void stop() override;

    ElectricMotor* clone() const override;
};