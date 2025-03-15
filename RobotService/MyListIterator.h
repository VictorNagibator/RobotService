#pragma once
#include "Iterator.h"
#include "Element.h"

//Конкретный итератор
template <typename T>
class MyListIterator : public Iterator<T>
{
private:
    Element<T>* current; //Текущий узел списка
    Element<T>* root; //Запоминаем корень для сброса итератора
public:
    MyListIterator(Element<T>* node) : current(node), root(node) {}

    bool hasNext() const 
    {
        return current != nullptr;
    }

    T* next()
    {
        if (!hasNext()) {
            throw std::exception("Итератор достиг конца коллекции!");
        }
        
        T* data = current->get(); //Берём данные текущего узла
        current = current->next(); //Переходим к следующему
        return data;
    }

    void reset()
    {
        current = root; //Просто сбрасываем до корня
    }
};