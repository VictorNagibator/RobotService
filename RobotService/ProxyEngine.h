#pragma once
#include "IEngine.h"

//Прокси для двигателя, проверяющий температуру перед запуском или изменением мощности
class EngineProxy : public IEngine {
private:
    IEngine* realEngine; //Реальный двигатель, которому делегируются вызовы
public:
    EngineProxy(IEngine* engine);

    void start() override;
    void setRPM(int newRPM) override;
};

