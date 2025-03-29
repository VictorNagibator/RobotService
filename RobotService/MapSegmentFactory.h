#pragma once
#include "MapSegment.h"
#include <unordered_map>
#include <sstream>

//Фабрика для создания и управления сегментами карты.
//Ключ формируется на основе названия улицы. Если сегмент уже создан, он возвращается повторно.
class MapSegmentFactory {
private:
    std::unordered_map<std::string, MapSegment*> pool;
public:
    ~MapSegmentFactory();

    //Возвращает сегмент карты для заданной улицы
    //Если сегмент отсутствует, создается новый
    MapSegment* getSegment(const std::string& streetName, int houseNum);
};
