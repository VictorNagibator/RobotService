#pragma once
#include "MapFeature.h"

class PedestrianCrossing : public MapFeature 
{
private:
    std::string location; //�������������� ��������
public:
    PedestrianCrossing(const std::string& loc) : location(loc) {}
    void printInfo() const override;
};