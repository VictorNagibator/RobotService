#pragma once
#include "IVendingMachine.h"

//Интерфейс команды для взаимодействия с автоматом
class ICommand {
protected:
	IVendingMachine* vendingMachine; //Указатель на автомат
public:
	ICommand(IVendingMachine* vendingMachine) : vendingMachine(vendingMachine) {}

	virtual void execute() = 0; //Выполнение команды
	virtual std::string name() const = 0; //Имя команды
};