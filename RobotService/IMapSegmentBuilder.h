#pragma once
#include "MapSegment.h"

//Интерфейс строителя сегмента карты
class IMapSegmentBuilder 
{
public:
    //Сбрасывает текущее состояние строителя
    virtual void reset() = 0;
    //Добавление нового сегмента
    virtual IMapSegmentBuilder& beginSegment(const std::string& streetName) = 0;
    //Добавление номеров домов к текущему сегменту
    virtual IMapSegmentBuilder& addHouseNumbers(const std::vector<int>& numbers) = 0;
    //Добавление дополнительного элемента (светофор, переход)
    virtual IMapSegmentBuilder& addFeature(MapFeature* feature) = 0;
    //Завершает сборку текущего сегмента
    virtual IMapSegmentBuilder& endSegment() = 0;
    //Возвращает готовый объект MapSegment
    virtual MapSegment* build() = 0;
};