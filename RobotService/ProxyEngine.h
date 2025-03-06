#pragma once
#include "IEngine.h"

//������ ��� ���������, ����������� ����������� ����� �������� ��� ���������� ��������
class ProxyEngine : public IEngine {
private:
    IEngine* realEngine; //�������� ���������, �������� ������������ ������
public:
    ProxyEngine(IEngine* engine);

    void start() override;
    void stop() override;
    void setRPM(int newRPM) override;
};