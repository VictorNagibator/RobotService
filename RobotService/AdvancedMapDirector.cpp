#include "AdvancedMapDirector.h"

MapSegment* AdvancedMapDirector::constructMap() const
{
	//А тут создаем подробную карту с разными точностями

    builder->reset();
    builder->beginSegment("пр. Ленина")
        .addHouseNumbers({ 1, 2, 3, 4, 5 })
        .addFeature(new TrafficLight("на перекрёстке с Молодежной"))
        .endSegment();
    builder->beginSegment("ул. Молодежная")
        .addHouseNumbers({ 10, 11, 12 })
        .addFeature(new PedestrianCrossing("на пересечении с Ленина"))
        .endSegment();
    builder->beginSegment("ул. Димитрова")
        .addHouseNumbers({ 20, 21, 22, 23 })
        .endSegment();
    return builder->build();
}