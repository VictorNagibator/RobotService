#pragma once
#include "CommunicationDecorator.h"

//Декоратор для шифровки отправляемого сообщения
class CommunicationEncryptorDecorator : public CommunicationDecorator
{
private:
	std::string encrypt(std::string message); //Метод шифрования
public:
	CommunicationEncryptorDecorator(ICommunication* comm) : CommunicationDecorator(comm) {}

	void sendData(const std::string& message) override;
};