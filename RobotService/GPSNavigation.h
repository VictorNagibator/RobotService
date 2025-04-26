#pragma once
#include "INavigation.h"
#include "StreetSegmentFactory.h"
#include "MapSegment.h"

//��������� � �������������� GPS
class GPSNavigation : public INavigation {
private:
    double accuracy; //�������� ��������� (� ������)
    int satelliteCount; //���������� ��������� ���������
	
	MapSegment* currentMap; //������� �����
public:
    GPSNavigation(IEnvironment* environment, MapSegment* map, 
        double accuracy, int satelliteCount, double startX = 0, double startY = 0);

	void updateMap(MapSegment* newMap);

    void navigate(const std::string& destination) override;
    void updatePosition(double newX, double newY) override;
    void adjustRoute() override;

	bool selfTest() const override;

    GPSNavigation* clone() const override;
};