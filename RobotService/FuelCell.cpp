#include "FuelCell.h"

double FuelCell::getCharge() const {
    return fuelLevel;
}

void FuelCell::recharge() {
    fuelLevel = capacity;
    std::cout << "Топливный бак полностью заправлен.\n";
}

void FuelCell::consume(double amount) {
    //Не может быть отрицательного топлива в баке
    fuelLevel = (fuelLevel - amount < 0 ? 0 : fuelLevel - amount);

    std::cout << "Топливо использовано. Текущий уровень: " << fuelLevel << " / " << capacity << ".\n";
}