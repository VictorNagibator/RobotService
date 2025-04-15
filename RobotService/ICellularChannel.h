#pragma once
#include <string>
#include <iostream>

//Интерфейс мобильного канала связи
class ICellularChannel {
public:
	virtual void connect() = 0; //Установить соединение
	virtual void transmit(const std::string& message) = 0; //Передать сообщение
	virtual void disconnect() = 0; //Закрыть соединение
};