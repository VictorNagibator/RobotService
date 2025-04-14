#pragma once
#include "INavigation.h"
#include "MapSegmentFactory.h"

//Навигация с использованием GPS
class GPSNavigation : public INavigation {
private:
    double accuracy; //Точность измерения (в метрах)
    int satelliteCount; //Количество доступных спутников
	MapSegmentFactory factory; //Фабрика для работы с сегментами карты
public:
    GPSNavigation(IEnvironment* environment, double accuracy, int satelliteCount, double startX = 0, double startY = 0);

    void navigate(const std::string& destination) override;
    void updatePosition(double newX, double newY) override;
    void adjustRoute() override;

    GPSNavigation* clone() const override;
};