#pragma once
#include <string>
#include "IEnvironment.h"
#include "Prototype.h"
#include "Visitable.h"

//Абстрактный класс для средств связи
class ICommunication : public Prototype, public Visitable {
protected:
    IEnvironment* environment; //Среда, в которой работает средство связи
    int signalStrength; //Сила сигнала
public:
    ICommunication(int signalStrength, IEnvironment* env);

    //Установление связи с центральным контроллером
    virtual void establishConnection() = 0;
	//Отключение от сети
	virtual void disconnect() = 0;
    //Передача данных о состоянии робота
    virtual void sendData(const std::string& data) = 0;
    //Приём управляющих команд от центрального контроллера
    virtual std::string receiveCommand() = 0;
    
	//Получение силы сигнала
	virtual int getSignalStrength() const;
    virtual IEnvironment* getEnvironment() const;

	//Можно поменять среду (например, робот попал под ливень или поменял способ передвижения)
	virtual void setEnvironment(IEnvironment* env);

	virtual ICommunication* clone() const = 0;

    virtual void accept(IComponentVisitor& v) const override;
};