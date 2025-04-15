#include "AdvancedMapDirector.h"

MapSegment* AdvancedMapDirector::constructMap() const
{
	//� ��� ������� ��������� ����� � ������� ����������

    builder->reset();
    builder->beginSegment("��. ������")
        .addHouseNumbers({ 1, 2, 3, 4, 5 })
        .addFeature(new TrafficLight("�� ���������� � ����������"))
        .endSegment();
    builder->beginSegment("��. ����������")
        .addHouseNumbers({ 10, 11, 12 })
        .addFeature(new PedestrianCrossing("�� ����������� � ������"))
        .endSegment();
    builder->beginSegment("��. ���������")
        .addHouseNumbers({ 20, 21, 22, 23 })
        .endSegment();
    return builder->build();
}