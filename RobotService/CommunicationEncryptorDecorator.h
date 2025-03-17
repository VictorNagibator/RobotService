#pragma once
#include "CommunicationDecorator.h"

//��������� ��� �������� ������������� ���������
class CommunicationEncryptorDecorator : public CommunicationDecorator
{
private:
	std::string encrypt(std::string message); //����� ����������
public:
	CommunicationEncryptorDecorator(ICommunication* comm) : CommunicationDecorator(comm) {}

	void sendData(const std::string& message) override;
};