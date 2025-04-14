#pragma once
#include "IEngine.h"
#include "IEnvironment.h"

class EngineFactory {
public:
    //Абстрактный метод, реализуемый  наследником,
    //создает и возвращает объект конкретного двигателя
    virtual IEngine* createEngine(const std::string& name, 
        int maxRMP, int temperatureThreshold, IEnvironment* environment) = 0;
};