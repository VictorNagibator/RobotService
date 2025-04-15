#include "StreetSegmentFactory.h"

StreetSegment* StreetSegmentFactory::getSegment(const std::string& streetName) 
{
    if (pool.find(streetName) == pool.end()) {
        pool[streetName] = new StreetSegment(streetName);
    }
    return pool[streetName];
}