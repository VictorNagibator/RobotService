#include "Battery.h"

Battery::Battery(int capacity, IEnvironment* environment)
{
    this->capacity = capacity;
    this->environment = environment;
}

double Battery::getCharge() const 
{
    return (currentCharge / capacity) * 100.0; //Переводим в проценты
}

void Battery::recharge()
{
    currentCharge = capacity;
    std::cout << "Батерея зарядилась до 100%.\n";
}

void Battery::consume(double usage) {
    if (currentCharge < usage) throw std::exception("Недостаточно энергии!");

	currentCharge -= usage;
    std::cout << "Батарея разряжается. Текущий заряд: " << getCharge() << "%\n";
}