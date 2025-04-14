#pragma once
#include "INavigation.h"

//Навигация с использованием визуального анализа
class VisionNavigation : public INavigation {
private:
    std::string resolution; //Разрешение камеры, например, "1080p"
    int frameRate; //Частота кадров (FPS)
public:
    VisionNavigation(IEnvironment* environment, const std::string& resolution, 
        int frameRate, double startX = 0, double startY = 0);

    void navigate(const std::string& destination) override;
    void updatePosition(double newX, double newY) override;
    void adjustRoute() override;

	VisionNavigation* clone() const override;
};