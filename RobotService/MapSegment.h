#pragma once
#pragma once
#include <string>
#include <set>
#include <iostream>

//Flyweight-объект для сегмента карты
//Сегмент содержит название улицы и список номеров домов на этом сегменте
class MapSegment {
private:
    std::string streetName;
    std::set<int> houseNumbers; //множество домов на сегменте
public:
    MapSegment(const std::string& street);

    //Добавляет номер дома в сегмент
    void addHouseNumber(int number);

    std::string getStreetName() const;

    //Проверяет, присутствует ли дом в сегменте
    bool hasHouse(int houseNumber) const;

    //Выводит информацию о сегменте
    void printInfo() const;
};