#include "DetailedMapSegmentBuilder.h"
#include "StreetSegmentFactory.h"

void DetailedMapSegmentBuilder::reset() 
{
	//���������� ������� ��������� ���������
    if (mapSegment) {
        delete mapSegment;
    }
    mapSegment = new MapSegment();
    currentSegment = nullptr;
}

IMapSegmentBuilder& DetailedMapSegmentBuilder::beginSegment
(const std::string& streetName) 
{
    if (currentSegment != nullptr) {
        //���� ���������� ������� ��� �� ��������, �������� ��� � �����
        mapSegment->addStreet(currentSegment);
    }

    //���������� ������� �� 8-�� ������ ��� �������� ��������� :)
    StreetSegmentFactory factory;

    currentSegment = factory.getSegment(streetName);
    return *this;
}

IMapSegmentBuilder& DetailedMapSegmentBuilder::addHouseNumbers(const std::vector<int>& numbers)
{
    if (currentSegment) {
		//���������� ������� ����� � �������� ��������
        for (int num : numbers) {
            currentSegment->addHouseNumber(num);
        }
    }
    return *this;
}

IMapSegmentBuilder& DetailedMapSegmentBuilder::addFeature(MapFeature* feature) 
{
    if (currentSegment) {
		//���������� ��������������� �������� (��������, �������)
        currentSegment->addFeature(feature);
    }
    return *this;
}

IMapSegmentBuilder& DetailedMapSegmentBuilder::endSegment() 
{
    if (currentSegment != nullptr) {
        mapSegment->addStreet(currentSegment);
        currentSegment = nullptr;
    }
    return *this;
}

MapSegment* DetailedMapSegmentBuilder::build() 
{
    if (currentSegment != nullptr) { //���� ��� �� ��������
        mapSegment->addStreet(currentSegment);
        currentSegment = nullptr;
    }
    return mapSegment;
}