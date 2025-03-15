#pragma once
#include "IAggregate.h"
#include "MyListIterator.h"

//������� ������ � ����������
template <typename T>
class MyList {
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

	//�� ����� ������, ��-�� ������� ����� ��������� ������ ������

	Iterator<T>* begin()
	{
		return new MyListIterator<T>(root);
	}

	Iterator<T>* end()
	{
		return new MyListIterator<T>(nullptr);
	}
};