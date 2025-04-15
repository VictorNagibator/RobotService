#pragma once
#include "IMapSegmentBuilder.h"
#include "IMapDirector.h"
#include "MapSegment.h"
#include "TrafficLight.h"
#include "PedestrianCrossing.h"

//���������� ��������, ������ ������� ����� � ������� ����������
class AdvancedMapDirector : public IMapDirector 
{
public:
    AdvancedMapDirector(IMapSegmentBuilder* b) : IMapDirector(b) {}

    MapSegment* constructMap() const override;
};