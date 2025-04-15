#include "BasicMapDirector.h"

MapSegment* BasicMapDirector::constructMap() const
{
    //Пример создания простой карты 
    
    builder->reset();
    builder->beginSegment("пр. Ленина")
        .addHouseNumbers({ 1, 2, 3, 4, 5 })
        .endSegment();
    builder->beginSegment("ул. Молодежная")
        .addHouseNumbers({ 10, 11, 12 })
        .endSegment();
    builder->beginSegment("пр. Космонавтов")
        .addHouseNumbers({ 20, 21, 22, 23 })
        .endSegment();
    return builder->build();
}