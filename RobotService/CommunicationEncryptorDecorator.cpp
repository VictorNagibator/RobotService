#include "CommunicationEncryptorDecorator.h"

std::string CommunicationEncryptorDecorator::encrypt(std::string data)
{
	//Можно будет добавить какое-нибудь серьезное шифрование. Сейчас для примера просто реверс строки
	return std::string(data.rbegin(), data.rend());
}

void CommunicationEncryptorDecorator::sendData(const std::string& data)
{
	std::string encryptedData = encrypt(data);
	wrappedComm->sendData(encryptedData); //Отправляем зашифрованные данные
}