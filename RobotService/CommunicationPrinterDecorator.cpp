#include "CommunicationPrinterDecorator.h"
#include <iostream>

//Вспомогательный метод для вывода сообщения на экран.
void CommunicationPrinterDecorator::printOnScreen(std::string data) 
{
    std::cout << "[Экран робота] " << data << std::endl;
}

//Перед делегированием вызова реальному объекту, выводится сообщение
void CommunicationPrinterDecorator::establishConnection() 
{
    printOnScreen("Подключаюсь...");
    //Делегируем вызов базовому декоратору (и, соответственно, реальному объекту)
    CommunicationDecorator::establishConnection();
    printOnScreen("Соединение установлено!");
}

//Сначала выводится сообщение, затем делегируется отправка
void CommunicationPrinterDecorator::sendData(const std::string& data) {
    printOnScreen("Отправляю данные...");
    CommunicationDecorator::sendData(data);
}

//Перед вызовом выводится сообщение, затем полученная команда выводится и возвращается
std::string CommunicationPrinterDecorator::receiveCommand() {
    printOnScreen("Получаю команду...");
    std::string cmd = CommunicationDecorator::receiveCommand();
    printOnScreen("Команда получена.");
    return cmd;
}