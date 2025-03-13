#pragma once
#include "INavigation.h"
#include "YandexNavigationSystem.h"

//�������, ����������� ��� ��������� INavigation
class YandexNavigationAdapter : public INavigation
{
private:
    //������ ������������ ������
    YandexNavigationSystem originalNav; 
public:
    YandexNavigationAdapter(double startX, double startY)
        : INavigation(startX, startY) {}

    void navigate(const std::string& destination) override;
    void updatePosition(double newX, double newY) override;
    void adjustRoute() override;
};