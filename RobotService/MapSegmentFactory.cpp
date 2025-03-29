#include "MapSegmentFactory.h"

//����� ���������� ������� ����� ������� ��� ��������� ��������
MapSegmentFactory::~MapSegmentFactory() {
    for (auto& pair : pool) {
        delete pair.second;
    }
}

MapSegment* MapSegmentFactory::getSegment(const std::string& streetName, int houseNum) 
{
    if (pool.find(streetName) == pool.end()) {
        pool[streetName] = new MapSegment(streetName);
    }
    //��������� ����� ���� � �������
    pool.at(streetName)->addHouseNumber(houseNum); 
    return pool[streetName];
}