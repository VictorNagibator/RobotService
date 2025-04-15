#pragma once
#include "StreetSegment.h"
#include <vector>
#include <iostream>

//Объект для отображения карты, состоящей из сегментов улиц
class MapSegment 
{
private:
    std::vector<StreetSegment*> segments;
public:
    void addStreet(StreetSegment* segment);
    void printMapInfo() const;

    //Проверка, есть ли такой адрес на карте
    bool hasAddress(const std::string& streetName, int houseNum) const;
};