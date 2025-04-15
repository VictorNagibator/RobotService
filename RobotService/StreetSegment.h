#pragma once
#include <string>
#include <set>
#include <vector>
#include <iostream>
#include "MapFeature.h"

//Flyweight-������ ��� �������� �����
//������� �������� �������� ����� � ������ ������� ����� �� ���� ��������
class StreetSegment {
private:
    std::string streetName;
    std::set<int> houseNumbers; //��������� ����� �� ��������

    std::vector<MapFeature*> features;  //�������������� ��������, ����� ��� ���������, ���������� ��������
public:
    StreetSegment(const std::string& street);

    //��������� ����� ���� � �������
    void addHouseNumber(int number);

    //��������� �������������� ������� �� �����
    void addFeature(MapFeature* feature);

    std::string getStreetName() const;

    //���������, ������������ �� ��� � ��������
    bool hasHouse(int houseNumber) const;

    //������� ���������� � ��������
    void printInfo() const;
};