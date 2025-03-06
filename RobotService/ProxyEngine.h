#pragma once
#include "IEngine.h"

//Прокси для двигателя, проверяющий температуру перед запуском или изменением мощности
class ProxyEngine : public IEngine {
private:
    IEngine* realEngine; //Реальный двигатель, которому делегируются вызовы
public:
    ProxyEngine(IEngine* engine);

    void start() override;
    void stop() override;
    void setRPM(int newRPM) override;
};