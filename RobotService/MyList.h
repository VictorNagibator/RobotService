#pragma once
#include "IAggregate.h"
#include "MyListIterator.h"

//������� ������ � ����������
template <typename T>
class MyList : public IAggregate<T> {
private:
    Element<T>* root = nullptr; //�������� ���� ������
public:
	~MyList() { if (root) delete root; } //��������� ����������� �������� ���� �����

    void push(const T& obj)
	{
		//���� ������ �� ����, ��������� ������� � �����
		if (root) {
			root->push(obj);
		}
		//����� ������� �������� ����
		else {
			root = new Element<T>(obj);
		}
    }

    void remove(const T& value) {
        if (!root) return; //������ ����

        //���� �������� ���� �������� �������� value, ������� ���
        if (*root->get() == value) {
            Element<T>* temp = root;
            root = root->next();  //����������� �������� ���� �� ���������
            //��������� ��������� ���� �� ������, ����� ��� ���������� �� ������ ���������� ����� ������
            temp->setNext(nullptr);
            delete temp;
            return;
        }

        //���� ����, �������������� ���������� ��������
        Element<T>* current = root;
        while (current->next() != nullptr && *current->next()->get() != value) {
            current = current->next();
        }

        //���� ������� ������, ������������ ����� � ������� ����
        if (current->next() != nullptr) {
            Element<T>* toRemove = current->next();
            current->setNext(toRemove->next()); //��������� �����: ���������� ��������� ����
            toRemove->setNext(nullptr); //��������� ��������� ���� �� ������
            delete toRemove;
        }
    }

	//�� ����� ������, ��-�� ������� ����� ��������� ������ ������

	//���������� �������� �� ������ ������
	Iterator<T>* begin()
	{
		return new MyListIterator<T>(root);
	}

	//���������� �������� �� ����� ������
	Iterator<T>* end()
	{
		return new MyListIterator<T>(nullptr);
	}
};