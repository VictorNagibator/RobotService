#pragma once
#include <string>
#include <iostream>

//Базовый класс для всех объектов карты
class MapFeature 
{
public:
    virtual void printInfo() const = 0;
};