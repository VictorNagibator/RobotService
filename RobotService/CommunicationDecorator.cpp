#include "CommunicationDecorator.h"

CommunicationDecorator::CommunicationDecorator(ICommunication* comm)
	: ICommunication(comm->getSignalStrength(), comm->getEnvironment())
{
	wrappedComm = comm;
}

//���������� � ������������� �������

void CommunicationDecorator::establishConnection()
{
	wrappedComm->establishConnection();
}

void CommunicationDecorator::sendData(const std::string& data)
{
	wrappedComm->sendData(data);
}

std::string CommunicationDecorator::receiveCommand()
{
	return wrappedComm->receiveCommand();
}