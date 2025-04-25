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
	int getRPM() const override;
	void setTemperature(int newTemperature) override;
	int getTemperature() const override;

	std::string getNameFromSnapshot() const override;
	int getMaxRPM() const override;
	int getTemperatureThreshold() const override;
};