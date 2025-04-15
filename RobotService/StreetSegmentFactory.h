#pragma once
#include "StreetSegment.h"
#include <unordered_map>
#include <sstream>

//Фабрика для создания и управления сегментами улицы
//Ключ формируется на основе названия улицы. Если сегмент уже создан, он возвращается повторно
class StreetSegmentFactory {
private:
    std::unordered_map<std::string, StreetSegment*> pool;
public:
    //Возвращает сегмент заданной улицы
    //Если сегмент отсутствует, создается новый
    StreetSegment* getSegment(const std::string& streetName);
};