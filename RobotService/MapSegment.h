#pragma once
#pragma once
#include <string>
#include <set>
#include <iostream>

//Flyweight-������ ��� �������� �����
//������� �������� �������� ����� � ������ ������� ����� �� ���� ��������
class MapSegment {
private:
    std::string streetName;
    std::set<int> houseNumbers; //��������� ����� �� ��������
public:
    MapSegment(const std::string& street);

    //��������� ����� ���� � �������
    void addHouseNumber(int number);

    std::string getStreetName() const;

    //���������, ������������ �� ��� � ��������
    bool hasHouse(int houseNumber) const;

    //������� ���������� � ��������
    void printInfo() const;
};