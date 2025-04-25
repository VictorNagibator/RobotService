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
	int getRPM() const override;
	void setTemperature(int newTemperature) override;
	int getTemperature() const override;

	std::string getNameFromSnapshot() const override;
	int getMaxRPM() const override;
	int getTemperatureThreshold() const override;
};