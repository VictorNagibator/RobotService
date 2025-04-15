#pragma once
#include "ICommunication.h"

//����� ��������� ��� �����������
class CommunicationDecorator : public ICommunication
{
protected:
	ICommunication* wrappedComm; //������������ ������
public:
	CommunicationDecorator(ICommunication* comm);
	
    void establishConnection() override;
	void disconnect() override;
    void sendData(const std::string& data) override;
    std::string receiveCommand() override;

	CommunicationDecorator* clone() const override;
};