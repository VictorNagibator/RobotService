#pragma once
#include "StreetSegment.h"
#include <vector>
#include <iostream>

//������ ��� ����������� �����, ��������� �� ��������� ����
class MapSegment 
{
private:
    std::vector<StreetSegment*> segments;
public:
    void addStreet(StreetSegment* segment);
    void printMapInfo() const;

    //��������, ���� �� ����� ����� �� �����
    bool hasAddress(const std::string& streetName, int houseNum) const;
};