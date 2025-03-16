#pragma once
#include "Iterator.h"

//Интерфейс агрегата (контейнера объектов)
template <typename T>
class IAggregate {
public:
    virtual void push(const T& obj) = 0; //Добавляет объект
	virtual void remove(const T& obj) = 0; //Удаляет объект
	virtual Iterator<T>* begin() = 0; //Возвращает итератор на начало контейнера
    virtual Iterator<T>* end() = 0; //Возвращает итератор на конец контейнера
};