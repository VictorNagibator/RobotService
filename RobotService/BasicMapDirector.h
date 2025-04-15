#pragma once
#include "IMapDirector.h"
#include "MapSegment.h"

//���������� ��������, ������ ������� �����, ��� ������ ���������
class BasicMapDirector : public IMapDirector
{
public:
    BasicMapDirector(IMapSegmentBuilder* b) : IMapDirector(b) {}

    MapSegment* constructMap() const override;
};