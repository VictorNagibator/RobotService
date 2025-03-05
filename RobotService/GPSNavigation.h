#pragma once
#include "INavigation.h"

//Навигация с использованием GPS
class GPSNavigation : public INavigation {
private:
    double accuracy; //Точность измерения (в метрах)
    int satelliteCount; //Количество доступных спутников
public:
    GPSNavigation(double accuracy, int satelliteCount, double startX = 0, double startY = 0);

    void navigate(const std::string& destination) override;
    void updatePosition(double newX, double newY) override;
    void adjustRoute() override;
};

