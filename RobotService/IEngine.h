#pragma once
#include <string>

class IEngine
{
protected:
    std::string engineName;
    int currentRPM = 0; //������� ������� ���������
    int maxRPM; //����������� ��������� �������
    int currentTemperature = 20; //������� �����������
    int temperatureThreshold; //����������� ��������� �����������

    //�����������, �� ������� ����� ���������� ����������� ��������� ��� ��������� ��� ��������� ��������
    const int temperatureDifference = 2; 
public:
    IEngine(const std::string& name, int maxRMP, int temperatureThreshold);
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void setRPM(int newRPM);
    virtual int getRPM();
    virtual void setTemperature(int newTemperature);
    virtual int getTemperature();

    virtual std::string getName();
    virtual int getMaxRPM();
    virtual int getTemperatureThreshold();
};