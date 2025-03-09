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
	int getRPM() override;
	void setTemperature(int newTemperature) override;
	int getTemperature() override;

	std::string getName() override;
	int getMaxRPM() override;
	int getTemperatureThreshold() override;
};