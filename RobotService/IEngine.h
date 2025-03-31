#pragma once
#include <string>
#include "IEnvironment.h"

class IEngine
{
protected:
    IEnvironment* environment; //Среда, в которой работает двигатель

    std::string engineName;
    int currentRPM = 0; //Текущие обороты двигателя
    int maxRPM; //Максимально возможные обороты
    int currentTemperature = 20; //Текущая температура
    int temperatureThreshold; //Максимально возможная температура

    //Температура, на которую будет изменяться температура двигателя при повышении или понижении оборотов
    const int temperatureDifference = 2; 
public:
    IEngine(const std::string& name, int maxRMP, int temperatureThreshold, IEnvironment* environment);
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void setRPM(int newRPM);
    virtual int getRPM() const;
    virtual void setTemperature(int newTemperature);
    virtual int getTemperature() const;

    virtual std::string getName() const;
    virtual int getMaxRPM() const;
    virtual int getTemperatureThreshold() const;

    //Можно поменять среду
    virtual void setEnvironment(IEnvironment* env) = 0;
};