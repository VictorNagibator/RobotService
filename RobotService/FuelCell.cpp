#include "FuelCell.h"

FuelCell::FuelCell(FuelType fuelType, int capacity)
{
    this->fuelType = fuelType;
    this->capacity = capacity;
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