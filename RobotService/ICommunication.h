#pragma once
#include <string>

//����������� ����� ��� ������� �����
class ICommunication {
protected:
    int signalStrength; //���� �������
public:
    //������������ ����� � ����������� ������������
    virtual void establishConnection() = 0;
    //�������� ������ � ��������� ������
    virtual void sendData(const std::string& data) = 0;
    //���� ����������� ������ �� ������������ �����������
    virtual std::string receiveCommand() = 0;
};