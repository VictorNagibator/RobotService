#pragma once
#include "IEngine.h"
#include "IEnvironment.h"

class EngineFactory {
public:
    //����������� �����, �����������  �����������,
    //������� � ���������� ������ ����������� ���������
    virtual IEngine* createEngine(const std::string& name, 
        int maxRMP, int temperatureThreshold, IEnvironment* environment) = 0;
};