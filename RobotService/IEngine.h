#pragma once
#include <string>

class IEngine
{
protected:
    std::string engineName;
    int currentRPM = 0; //Текущие обороты двигателя
    int maxRPM; //Максимально возможные обороты
    int currentTemperature = 20; //Текущая температура
    int temperatureThreshold; //Максимально возможная температура

    //Температура, на которую будет изменяться температура двигателя при повышении или понижении оборотов
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