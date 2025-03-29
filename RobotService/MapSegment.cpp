#include "MapSegment.h"

MapSegment::MapSegment(const std::string& street)
{
	streetName = street;
}

void MapSegment::addHouseNumber(int number) 
{
    houseNumbers.insert(number);
}

std::string MapSegment::getStreetName() const
{
    return streetName;
}

bool MapSegment::hasHouse(int houseNumber) const 
{
    return houseNumbers.find(houseNumber) != houseNumbers.end();
}

void MapSegment::printInfo() const
{
    std::cout << "Сегмент улицы " << streetName
        << ". Дома: ";
    for (int num : houseNumbers)
        std::cout << num << " ";
    std::cout << "\n";
}