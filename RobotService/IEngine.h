#pragma once
#include <string>
#include "IEnvironment.h"
#include "Prototype.h"

class IEngine : public Prototype
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

    virtual std::string getNameFromSnapshot() const;
    virtual int getMaxRPM() const;
    virtual int getTemperatureThreshold() const;
    IEnvironment* getEnvironment() const;

    //Можно поменять среду
    virtual void setEnvironment(IEnvironment* env);
    
	//Можно уточнить возвращаемый тип, так как IEngine является наследником Prototype
	virtual IEngine* clone() const = 0;
};