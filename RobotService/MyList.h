#pragma once
#include "IAggregate.h"
#include "MyListIterator.h"

//Связный список с итератором
template <typename T>
class MyList : public IAggregate<T> {
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

    void remove(const T& value) {
        if (!root) return; //Список пуст

        //Если корневой узел содержит значение value, удаляем его
        if (*root->get() == value) {
            Element<T>* temp = root;
            root = root->next();  //Переключаем корневой узел на следующий
            //Отключаем удаляемый узел от списка, чтобы его деструктор не удалил оставшуюся часть списка
            temp->setNext(nullptr);
            delete temp;
            return;
        }

        //Ищем узел, предшествующий удаляемому элементу
        Element<T>* current = root;
        while (current->next() != nullptr && *current->next()->get() != value) {
            current = current->next();
        }

        //Если элемент найден, корректируем связь и удаляем узел
        if (current->next() != nullptr) {
            Element<T>* toRemove = current->next();
            current->setNext(toRemove->next()); //Обновляем связь: пропускаем удаляемый узел
            toRemove->setNext(nullptr); //Отключаем удаляемый узел от списка
            delete toRemove;
        }
    }

	//Те самые методы, из-за которых может произойти утечка памяти

	//Возвращает итератор на начало списка
	Iterator<T>* begin()
	{
		return new MyListIterator<T>(root);
	}

	//Возвращает итератор на конец списка
	Iterator<T>* end()
	{
		return new MyListIterator<T>(nullptr);
	}
};