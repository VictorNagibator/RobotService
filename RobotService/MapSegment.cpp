#include "MapSegment.h"

void MapSegment::addStreet(StreetSegment* segment)
{
    segments.push_back(segment);
}

void MapSegment::printMapInfo() const
{
    std::cout << "Информация о сегменте карты:\n";
    for (auto seg : segments)
        seg->printInfo();
}

bool MapSegment::hasAddress(const std::string& streetName, int houseNum) const
{
	for (const auto& segment : segments) {
		if (segment->getStreetName() == streetName && segment->hasHouse(houseNum)) {
			return true;
		}
	}
	return false;
}