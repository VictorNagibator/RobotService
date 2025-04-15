#pragma once
#include <string>
#include <iostream>

//��������� ������ �����
class CommunicationChannel {
public:
	virtual void connect() = 0; //���������� ����������
	virtual void transmit(const std::string& message) = 0; //�������� ���������
	virtual void disconnect() = 0; //������� ����������
};