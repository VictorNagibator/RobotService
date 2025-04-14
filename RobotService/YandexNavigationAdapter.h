#pragma once
#include "INavigation.h"
#include "YandexNavigationSystem.h"

//Адаптер, реализующий наш интерфейс INavigation
class YandexNavigationAdapter : public INavigation
{
private:
    //Храним адаптируемый объект
    YandexNavigationSystem originalNav; 
public:
    YandexNavigationAdapter(IEnvironment* environment, double startX, double startY)
        : INavigation(environment, startX, startY) {}

    void navigate(const std::string& destination) override;
    void updatePosition(double newX, double newY) override;
    void adjustRoute() override;

    YandexNavigationAdapter* clone() const override;
};