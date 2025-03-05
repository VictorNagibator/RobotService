#pragma once
#include "IEngine.h"

//��������� ���������
class HybridEngine : public IEngine {
private:
    //��������� ���-�� ������� ����� ���������� ����������� �������� � ��������������
    const int RPMonInitial = maxRPM * 0.7;
public:
    HybridEngine(const std::string& name, int maxRPM, int temperatureThreshold)
        : IEngine(name, maxRPM, temperatureThreshold) {}

    void start() override;
    void stop() override;
};