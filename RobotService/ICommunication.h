#pragma once
#include <string>
#include "IEnvironment.h"
#include "IPrototypeCommunication.h"

//јбстрактный класс дл€ средств св€зи
class ICommunication : public IPrototypeCommunication {
protected:
    IEnvironment* environment; //—реда, в которой работает средство св€зи
    int signalStrength; //—ила сигнала
public:
    ICommunication(int signalStrength, IEnvironment* env);

    //”становление св€зи с центральным контроллером
    virtual void establishConnection() = 0;
    //ѕередача данных о состо€нии робота
    virtual void sendData(const std::string& data) = 0;
    //ѕриЄм управл€ющих команд от центрального контроллера
    virtual std::string receiveCommand() = 0;
    
	//ѕолучение силы сигнала
	int getSignalStrength() const;
    IEnvironment* getEnvironment() const;

	//ћожно помен€ть среду (например, робот попал под ливень или помен€л способ передвижени€)
	virtual void setEnvironment(IEnvironment* env);

	virtual ICommunication* clone() const = 0;
};