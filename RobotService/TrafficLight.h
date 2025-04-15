#pragma once
#include "MapFeature.h"

//Класс для представления светофора на карте
class TrafficLight : public MapFeature 
{
private:
    std::string location; //Местоположение светофора на сегменте
public:
    TrafficLight(const std::string& loc) : location(loc) {}
    void printInfo() const override;
};
