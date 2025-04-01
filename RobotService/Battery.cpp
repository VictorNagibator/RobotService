#include "Battery.h"

Battery::Battery(int capacity, IEnvironment* environment) : IPowerSource(environment)
{
    this->capacity = capacity;
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
    environment->interact(); //При потреблении энергии среда движения так или иначе влияет
    std::cout << "Батарея разряжается. Текущий заряд: " << getCharge() << "%\n";
}