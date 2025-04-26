#pragma once
#include "INavigation.h"

//��������� � �������������� ����������� �������
class VisionNavigation : public INavigation {
private:
    std::string resolution; //���������� ������, ��������, "1080p"
    int frameRate; //������� ������ (FPS)
public:
    VisionNavigation(IEnvironment* environment, const std::string& resolution, 
        int frameRate, double startX = 0, double startY = 0);

    void navigate(const std::string& destination) override;
    void updatePosition(double newX, double newY) override;
    void adjustRoute() override;
    
	bool selfTest() const override;

	VisionNavigation* clone() const override;
};