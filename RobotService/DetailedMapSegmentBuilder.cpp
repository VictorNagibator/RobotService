#include "DetailedMapSegmentBuilder.h"
#include "StreetSegmentFactory.h"

void DetailedMapSegmentBuilder::reset() 
{
	//Сбрасывает текущее состояние строителя
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
        //Если предыдущий сегмент ещё не завершён, добавить его к карте
        mapSegment->addStreet(currentSegment);
    }

    //Используем фабрику из 8-ой работы для создания сегментов :)
    StreetSegmentFactory factory;

    currentSegment = factory.getSegment(streetName);
    return *this;
}

IMapSegmentBuilder& DetailedMapSegmentBuilder::addHouseNumbers(const std::vector<int>& numbers)
{
    if (currentSegment) {
		//Добавление номеров домов к текущему сегменту
        for (int num : numbers) {
            currentSegment->addHouseNumber(num);
        }
    }
    return *this;
}

IMapSegmentBuilder& DetailedMapSegmentBuilder::addFeature(MapFeature* feature) 
{
    if (currentSegment) {
		//Добавление дополнительного элемента (светофор, переход)
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
    if (currentSegment != nullptr) { //если ещё не завершён
        mapSegment->addStreet(currentSegment);
        currentSegment = nullptr;
    }
    return mapSegment;
}