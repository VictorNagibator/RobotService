#pragma once
#include "IRobot.h"

//Интерфейс части цепочки диагностики робота
class DiagnosticHandler {
protected:
	DiagnosticHandler* next; //Указатель на следующую часть цепочки диагностики
public:
    DiagnosticHandler() : next(nullptr) {}

	void setNext(DiagnosticHandler* next); //Установка следующей части цепочки диагностики
	virtual bool handle(const IRobot& robot); //Обработка диагностики
};