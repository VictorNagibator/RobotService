#pragma once
#include "IPowerSource.h"
#include "FuelType.h"

class FuelCell : public IPowerSource {
private:
    FuelType fuelType; //Тип топлива (например, дизель или 95)
    double fuelLevel; //Текущий уровень топлива
    int capacity; //Вместимость топливного бака
public:
    FuelCell(FuelType fuelType, int capacity);

    //Возвращает текущий уровень топлива
    double getCharge() const override;

    //Заправляет топливный элемент до 100%
    void recharge() override;

    //Симуляция расхода топлива.
    void consume(double amount) override;
};

