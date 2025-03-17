#pragma once
#include "CommunicationDecorator.h"
class CommunicationTimestampDecorator : public CommunicationDecorator
{
private:
    //Метод для получения текущей отметки времени в виде строки
    std::string getTimestamp();
public:
	CommunicationTimestampDecorator(ICommunication* comm) : CommunicationDecorator(comm) {}

	void sendData(const std::string& data) override;
};