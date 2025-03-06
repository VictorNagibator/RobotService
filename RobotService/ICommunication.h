#pragma once
#include <string>

//Абстрактный класс для средств связи
class ICommunication {
protected:
    int signalStrength; //Сила сигнала
public:
    ICommunication(int signalStrength);

    //Установление связи с центральным контроллером
    virtual void establishConnection() = 0;
    //Передача данных о состоянии робота
    virtual void sendData(const std::string& data) = 0;
    //Приём управляющих команд от центрального контроллера
    virtual std::string receiveCommand() = 0;
};