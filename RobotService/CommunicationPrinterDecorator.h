#pragma once
#include "CommunicationDecorator.h"

class CommunicationPrinterDecorator : public CommunicationDecorator
{
private:
	void printOnScreen(std::string data);
public:
	CommunicationPrinterDecorator(ICommunication* comm) : CommunicationDecorator(comm) {}

	void establishConnection() override;
	void sendData(const std::string& data) override;
	std::string receiveCommand() override;
};