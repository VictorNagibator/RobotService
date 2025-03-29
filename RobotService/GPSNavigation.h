#pragma once
#include "INavigation.h"
#include "MapSegmentFactory.h"

//��������� � �������������� GPS
class GPSNavigation : public INavigation {
private:
    double accuracy; //�������� ��������� (� ������)
    int satelliteCount; //���������� ��������� ���������
	MapSegmentFactory factory; //������� ��� ������ � ���������� �����

    //��������������� ������� ��� ������� ��������
    std::string trim(const std::string& s);
public:
    GPSNavigation(double accuracy, int satelliteCount, double startX = 0, double startY = 0);

    void navigate(const std::string& destination) override;
    void updatePosition(double newX, double newY) override;
    void adjustRoute() override;
};