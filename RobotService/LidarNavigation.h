#pragma once
#include "INavigation.h"

//��������� � �������������� Lidar
class LidarNavigation : public INavigation {
private:
    int detectionRange; //�������� ����������� (� ������)
    double laserFrequency; //������� ������ ������ (� ��)
public:
    LidarNavigation(IEnvironment* environment, int detectionRange, 
        double laserFrequency, double startX = 0, double startY = 0);

    void navigate(const std::string& destination) override;
    void updatePosition(double newX, double newY) override;
    void adjustRoute() override;

    LidarNavigation* clone() const override;
};
