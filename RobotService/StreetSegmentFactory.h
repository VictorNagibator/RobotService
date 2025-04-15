#pragma once
#include "StreetSegment.h"
#include <unordered_map>
#include <sstream>

//������� ��� �������� � ���������� ���������� �����
//���� ����������� �� ������ �������� �����. ���� ������� ��� ������, �� ������������ ��������
class StreetSegmentFactory {
private:
    std::unordered_map<std::string, StreetSegment*> pool;
public:
    //���������� ������� �������� �����
    //���� ������� �����������, ��������� �����
    StreetSegment* getSegment(const std::string& streetName);
};