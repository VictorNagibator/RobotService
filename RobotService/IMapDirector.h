#pragma once
#include "IMapSegmentBuilder.h"

//Интерфейс директора для построения карты
class IMapDirector
{
protected:
    IMapSegmentBuilder* builder; //Возможность конфигурации разными строителями
public:
    IMapDirector(IMapSegmentBuilder* b) : builder(b) {}

	virtual MapSegment* constructMap() const = 0; //Метод для построения карты
};