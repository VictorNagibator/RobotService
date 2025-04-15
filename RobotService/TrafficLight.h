#pragma once
#include "MapFeature.h"

//����� ��� ������������� ��������� �� �����
class TrafficLight : public MapFeature 
{
private:
    std::string location; //�������������� ��������� �� ��������
public:
    TrafficLight(const std::string& loc) : location(loc) {}
    void printInfo() const override;
};
