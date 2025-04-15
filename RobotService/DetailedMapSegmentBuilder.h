#pragma once
#include "IMapSegmentBuilder.h"
#include "MapSegment.h"

//���������� ���������
class DetailedMapSegmentBuilder : public IMapSegmentBuilder 
{
private:
	MapSegment* mapSegment; //�������� ������ �����, ������� ����� ����������
    StreetSegment* currentSegment; //������� �������, ������� ��������� � �������� ������
public:
    DetailedMapSegmentBuilder() : mapSegment(new MapSegment()), currentSegment(nullptr) {}

    void reset() override;
    IMapSegmentBuilder& beginSegment(const std::string& streetName) override;
    IMapSegmentBuilder& addHouseNumbers(const std::vector<int>& numbers) override;
    IMapSegmentBuilder& addFeature(MapFeature* feature) override;
    IMapSegmentBuilder& endSegment() override;
    MapSegment* build() override;
};