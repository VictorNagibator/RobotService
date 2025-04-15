#pragma once
#include "IMapDirector.h"
#include "MapSegment.h"

//Конкретный директор, строит обычную карту, без разных точностей
class BasicMapDirector : public IMapDirector
{
public:
    BasicMapDirector(IMapSegmentBuilder* b) : IMapDirector(b) {}

    MapSegment* constructMap() const override;
};