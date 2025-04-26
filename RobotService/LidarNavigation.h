#pragma once
#include "INavigation.h"

//Навигация с использованием Lidar
class LidarNavigation : public INavigation {
private:
    int detectionRange; //Диапазон обнаружения (в метрах)
    double laserFrequency; //Частота работы лазера (в Гц)
public:
    LidarNavigation(IEnvironment* environment, int detectionRange, 
        double laserFrequency, double startX = 0, double startY = 0);

    void navigate(const std::string& destination) override;
    void updatePosition(double newX, double newY) override;
    void adjustRoute() override;

	bool selfTest() const override;

    LidarNavigation* clone() const override;
};
