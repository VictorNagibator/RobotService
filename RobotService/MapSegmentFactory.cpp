#include "MapSegmentFactory.h"

//После разрушения фабрики нужно удалить все созданные сегменты
MapSegmentFactory::~MapSegmentFactory() {
    for (auto& pair : pool) {
        delete pair.second;
    }
}

MapSegment* MapSegmentFactory::getSegment(const std::string& streetName, int houseNum) 
{
    if (pool.find(streetName) == pool.end()) {
        pool[streetName] = new MapSegment(streetName);
    }
    //Добавляем номер дома в сегмент
    pool.at(streetName)->addHouseNumber(houseNum); 
    return pool[streetName];
}