#pragma once
#include <string>
#include "IEnvironment.h"

//����������� ����� ��� ������� �����
class ICommunication {
protected:
    IEnvironment* environment; //�����, � ������� �������� �������� �����
    int signalStrength; //���� �������
public:
    ICommunication(int signalStrength, IEnvironment* env);

    //������������ ����� � ����������� ������������
    virtual void establishConnection() = 0;
    //�������� ������ � ��������� ������
    virtual void sendData(const std::string& data) = 0;
    //���� ����������� ������ �� ������������ �����������
    virtual std::string receiveCommand() = 0;
    
	//��������� ���� �������
	int getSignalStrength() const;
    IEnvironment* getEnvironment() const;

	//����� �������� ����� (��������, ����� ����� ��� ������ ��� ������� ������ ������������)
	virtual void setEnvironment(IEnvironment* env) = 0;
};