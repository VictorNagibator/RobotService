#pragma once
#include "IMapSegmentBuilder.h"
#include "MapSegment.h"

//Конкретный строитель
class DetailedMapSegmentBuilder : public IMapSegmentBuilder 
{
private:
	MapSegment* mapSegment; //Основной объект карты, который будет собираться
    StreetSegment* currentSegment; //Текущий сегмент, который находится в процессе сборки
public:
    DetailedMapSegmentBuilder() : mapSegment(new MapSegment()), currentSegment(nullptr) {}

    void reset() override;
    IMapSegmentBuilder& beginSegment(const std::string& streetName) override;
    IMapSegmentBuilder& addHouseNumbers(const std::vector<int>& numbers) override;
    IMapSegmentBuilder& addFeature(MapFeature* feature) override;
    IMapSegmentBuilder& endSegment() override;
    MapSegment* build() override;
};