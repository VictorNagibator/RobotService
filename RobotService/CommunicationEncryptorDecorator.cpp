#include "CommunicationEncryptorDecorator.h"

std::string CommunicationEncryptorDecorator::encrypt(std::string data)
{
	//����� ����� �������� �����-������ ��������� ����������. ������ ��� ������� ������ ������ ������
	return std::string(data.rbegin(), data.rend());
}

void CommunicationEncryptorDecorator::sendData(const std::string& data)
{
	std::string encryptedData = encrypt(data);
	wrappedComm->sendData(encryptedData); //���������� ������������� ������
}