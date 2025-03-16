#pragma once

//Интерфейс итератора
template <typename T>
class Iterator {
public:
    virtual bool hasNext() const = 0; //Проверяет, есть ли следующий элемент
    virtual T* next() = 0; //Возвращает данные текущего элемента и переходит к следующему
    virtual void reset() = 0; //Сбрасывает итератор в начало
};