#pragma once
#include <string>

//����������� ����� ������������� �������
class INavigation {
protected:
    double x, y; //���������� ������
public:
    INavigation(double startX = 0, double startY = 0);

    //��������� �� �������� � �������� �����
    virtual void navigate(const std::string& destination) = 0;
    //���������� ��������� ������
    virtual void updatePosition(double newX, double newY);
    //��������� �������� ��� ������������� �����������
    virtual void adjustRoute() = 0;
};