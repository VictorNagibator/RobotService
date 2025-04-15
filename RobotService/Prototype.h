#pragma once

//Интерфейс прототипа
//Представляет требование в реализации лишь одного метода - clone()
class Prototype
{
public:
	virtual Prototype* clone() const = 0;
};