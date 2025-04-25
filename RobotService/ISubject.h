#pragma once
#include "IObserver.h"

//Интерфейс субъекта (наблюдаемого объекта)
class ISubject
{
public:
	//Добавление и удаление наблюдателей
	virtual void attach(IObserver* observer) = 0;
	virtual void detach(IObserver* observer) = 0;

	//Уведомление наблюдателей
	virtual void notify() = 0;
};