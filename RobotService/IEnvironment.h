#pragma once
#include <string>

//��������� ����� ������������
class IEnvironment {
public:
    //����������� ������������� ����� (��������, ������ ��� ������������� ����)
    virtual double getResistance() const = 0;
    //����������� �������� ��������� (��������, ������� �������� �������)
    virtual double getNavigationAccuracyFactor() const = 0;
    //����������� ��������� ������� ��� ������� �����
    virtual double getCommunicationAttenuation() const = 0;

    //�������������� �����-�� �� ������
    virtual void interact() = 0;

    //�������� �������� ����� �����
    virtual std::string getEnvironmentName() const = 0;
};