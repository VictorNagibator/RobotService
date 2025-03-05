#pragma once
#include "IEngine.h"

//������ ��� ���������, ����������� ����������� ����� �������� ��� ���������� ��������
class EngineProxy : public IEngine {
private:
    IEngine* realEngine; //�������� ���������, �������� ������������ ������
public:
    EngineProxy(IEngine* engine);

    void start() override;
    void setRPM(int newRPM) override;
};

