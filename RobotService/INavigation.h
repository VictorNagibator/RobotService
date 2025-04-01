#pragma once
#include <string>
#include "IEnvironment.h"

//����������� ����� ������������� �������
class INavigation {
protected:
    IEnvironment* environment;

    double x, y; //���������� ������
public:
    INavigation(IEnvironment* environment, double startX = 0, double startY = 0);

    //��������� �� �������� � �������� �����
    virtual void navigate(const std::string& destination) = 0;
    //���������� ��������� ������
    virtual void updatePosition(double newX, double newY);
    //��������� �������� ��� ������������� �����������
    virtual void adjustRoute() = 0;

    //����� �������� �����
    virtual void setEnvironment(IEnvironment* env);
    IEnvironment* getEnvironment() const;
};