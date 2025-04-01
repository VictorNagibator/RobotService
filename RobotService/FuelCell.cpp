#include "FuelCell.h"

FuelCell::FuelCell(FuelType fuelType, int capacity, IEnvironment* environment)
{
    this->fuelType = fuelType;
    this->capacity = capacity;
    this->environment = environment;
}

double FuelCell::getCharge() const {
    return fuelLevel;
}

void FuelCell::recharge() {
    fuelLevel = capacity;
    std::cout << "Топливный бак полностью заправлен.\n";
}

void FuelCell::consume(double amount) {
    //Не может быть отрицательного топлива в баке
    if (fuelLevel < amount) throw std::exception("Недостаточно топлива!");
    fuelLevel -= amount;

    std::cout << "Топливо использовано. Текущий уровень: " << fuelLevel << " / " << capacity << ".\n";
}