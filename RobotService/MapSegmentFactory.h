#pragma once
#include "MapSegment.h"
#include <unordered_map>
#include <sstream>

//������� ��� �������� � ���������� ���������� �����.
//���� ����������� �� ������ �������� �����. ���� ������� ��� ������, �� ������������ ��������.
class MapSegmentFactory {
private:
    std::unordered_map<std::string, MapSegment*> pool;
public:
    ~MapSegmentFactory();

    //���������� ������� ����� ��� �������� �����
    //���� ������� �����������, ��������� �����
    MapSegment* getSegment(const std::string& streetName, int houseNum);
};
