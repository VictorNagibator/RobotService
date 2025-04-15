#include "StreetSegment.h"

StreetSegment::StreetSegment(const std::string& street)
{
	streetName = street;
}

void StreetSegment::addHouseNumber(int number) 
{
    houseNumbers.insert(number);
}

void StreetSegment::addFeature(MapFeature* feature)
{
    features.push_back(feature);
}

std::string StreetSegment::getStreetName() const
{
    return streetName;
}

bool StreetSegment::hasHouse(int houseNumber) const 
{
    return houseNumbers.find(houseNumber) != houseNumbers.end();
}

void StreetSegment::printInfo() const
{
    std::cout << "������� ����� " << streetName
        << ". ����: ";
    for (int num : houseNumbers)
        std::cout << num << " ";
    std::cout << "\n�������������� �������:\n";
    for (auto feature : features)
        feature->printInfo();
}