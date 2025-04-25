#pragma once
#include <string>

//Интерфейс наблюдателя
class IObserver
{
public:
	virtual void update(const std::string& message) = 0;
};