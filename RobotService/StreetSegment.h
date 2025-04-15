#pragma once
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include "MapFeature.h"

//Flyweight-объект для сегмента улицы
//Сегмент содержит название улицы и список номеров домов на этом сегменте
class StreetSegment {
private:
    std::string streetName;
    std::set<int> houseNumbers; //множество домов на сегменте

    std::vector<MapFeature*> features;  //дополнительные элементы, такие как светофоры, пешеходные переходы
public:
    StreetSegment(const std::string& street);

    //Добавляет номер дома в сегмент
    void addHouseNumber(int number);

    //Добавляет дополнительный элемент на улицу
    void addFeature(MapFeature* feature);

    std::string getStreetName() const;

    //Проверяет, присутствует ли дом в сегменте
    bool hasHouse(int houseNumber) const;

    //Выводит информацию о сегменте
    void printInfo() const;
};