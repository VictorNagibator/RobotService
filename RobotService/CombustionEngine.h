#pragma once
#include "IEngine.h"

//��������� ����������� ��������
class CombustionEngine : public IEngine {
private:
    //������ ��������� ����������� �������� ��������� ����� �������
    const int RPMonInitial = (maxRPM > 1000) ? 1000 : maxRPM;
public:
    CombustionEngine(const std::string& name, int maxRPM, int temperatureThreshold, IEnvironment* environment)
        : IEngine(name, maxRPM, temperatureThreshold, environment) {}

    void start() override;
    void stop() override;
};