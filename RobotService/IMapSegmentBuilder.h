#pragma once
#include "MapSegment.h"

//��������� ��������� �������� �����
class IMapSegmentBuilder 
{
public:
    //���������� ������� ��������� ���������
    virtual void reset() = 0;
    //���������� ������ ��������
    virtual IMapSegmentBuilder& beginSegment(const std::string& streetName) = 0;
    //���������� ������� ����� � �������� ��������
    virtual IMapSegmentBuilder& addHouseNumbers(const std::vector<int>& numbers) = 0;
    //���������� ��������������� �������� (��������, �������)
    virtual IMapSegmentBuilder& addFeature(MapFeature* feature) = 0;
    //��������� ������ �������� ��������
    virtual IMapSegmentBuilder& endSegment() = 0;
    //���������� ������� ������ MapSegment
    virtual MapSegment* build() = 0;
};