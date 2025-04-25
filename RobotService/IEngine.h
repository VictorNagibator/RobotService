#pragma once
#include <string>
#include "IEnvironment.h"
#include "Prototype.h"

class IEngine : public Prototype
{
protected:
    IEnvironment* environment; //�����, � ������� �������� ���������

    std::string engineName;
    int currentRPM = 0; //������� ������� ���������
    int maxRPM; //����������� ��������� �������
    int currentTemperature = 20; //������� �����������
    int temperatureThreshold; //����������� ��������� �����������

    //�����������, �� ������� ����� ���������� ����������� ��������� ��� ��������� ��� ��������� ��������
    const int temperatureDifference = 2; 
public:
    IEngine(const std::string& name, int maxRMP, int temperatureThreshold, IEnvironment* environment);
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void setRPM(int newRPM);
    virtual int getRPM() const;
    virtual void setTemperature(int newTemperature);
    virtual int getTemperature() const;

    virtual std::string getNameFromSnapshot() const;
    virtual int getMaxRPM() const;
    virtual int getTemperatureThreshold() const;
    IEnvironment* getEnvironment() const;

    //����� �������� �����
    virtual void setEnvironment(IEnvironment* env);
    
	//����� �������� ������������ ���, ��� ��� IEngine �������� ����������� Prototype
	virtual IEngine* clone() const = 0;
};