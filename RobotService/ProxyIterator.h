#pragma once
#include "Iterator.h"

//Прокси итератор для корректной очистки памяти
template <typename T>
class ProxyIterator : public Iterator<T>
{
private:
	Iterator<T>* realIterator; //Реальный объект итератора
public:
	ProxyIterator(Iterator<T>* it) : realIterator(it) {}
	~ProxyIterator() { delete realIterator; } //Удаляем реальный итератор

	//Все остальные методы выполняет реальный объект

	bool hasNext() const override
	{
		return realIterator->hasNext();
	}

	T* next() override
	{
		return realIterator->next();
	}

	void reset() override
	{
		realIterator->reset();
	}
};