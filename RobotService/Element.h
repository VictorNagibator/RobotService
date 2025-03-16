#pragma once
#include <memory>

//Реализация в .h файлах из-за использования шаблонов

//Элемент списка
template <typename T>
class Element {
private:
    T object; //Сам объект
    Element<T>* nextNode = nullptr; //Указатель на следующий элемент
public:
    Element(const T& obj) : object(obj) {}
	~Element() { delete nextNode; }

	void push(const T& obj)
	{
        //Если следующий элемент уже существует, то передаем ему объект
        if (nextNode)
        {
            nextNode->push(obj);
        }
        //Иначе создаем новый элемент
        else
        {
            nextNode = new Element<T>(obj);
        }
	}

	T* get() //Получить объект
    {
        return &object;
    }

    Element<T>* next() //Получить следующий элемент
    {
		return nextNode;
    }

    //Позволяет обновить указатель на следующий узел.
    void setNext(Element<T>* next) 
    {
        nextNode = next;
    }
};