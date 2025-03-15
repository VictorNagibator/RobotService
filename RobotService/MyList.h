#pragma once
#include "IAggregate.h"
#include "MyListIterator.h"

//Связный список с итератором
template <typename T>
class MyList {
private:
    Element<T>* root = nullptr; //Корневой узел списка
public:
	~MyList() { if (root) delete root; } //Запускаем рекурсивное удаление всех узлов

    void push(const T& obj)
	{
		//Если список не пуст, добавляем элемент в конец
		if (root) {
			root->push(obj);
		}
		//Иначе создаем корневой узел
		else {
			root = new Element<T>(obj);
		}
    }

	//Те самые методы, из-за которых может произойти утечка памяти

	Iterator<T>* begin()
	{
		return new MyListIterator<T>(root);
	}

	Iterator<T>* end()
	{
		return new MyListIterator<T>(nullptr);
	}
};