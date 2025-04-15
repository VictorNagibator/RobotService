#pragma once
#include "ICommunication.h"

//Общий интерфейс для декораторов
class CommunicationDecorator : public ICommunication
{
protected:
	ICommunication* wrappedComm; //Декорируемый объект
public:
	CommunicationDecorator(ICommunication* comm);
	
    void establishConnection() override;
	void disconnect() override;
    void sendData(const std::string& data) override;
    std::string receiveCommand() override;

	CommunicationDecorator* clone() const override;
};