#pragma once
#include "INavigation.h"

//��������� � �������������� GPS
class GPSNavigation : public INavigation {
private:
    double accuracy; //�������� ��������� (� ������)
    int satelliteCount; //���������� ��������� ���������
public:
    GPSNavigation(double accuracy, int satelliteCount, double startX = 0, double startY = 0);

    void navigate(const std::string& destination) override;
    void updatePosition(double newX, double newY) override;
    void adjustRoute() override;
};

