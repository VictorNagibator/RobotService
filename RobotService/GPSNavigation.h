#pragma once
#include "INavigation.h"
#include "MapSegmentFactory.h"

//��������� � �������������� GPS
class GPSNavigation : public INavigation {
private:
    double accuracy; //�������� ��������� (� ������)
    int satelliteCount; //���������� ��������� ���������
	MapSegmentFactory factory; //������� ��� ������ � ���������� �����
public:
    GPSNavigation(IEnvironment* environment, double accuracy, int satelliteCount, double startX = 0, double startY = 0);

    void navigate(const std::string& destination) override;
    void updatePosition(double newX, double newY) override;
    void adjustRoute() override;

    GPSNavigation* clone() const override;
};