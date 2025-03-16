#pragma once
#include <memory>

//���������� � .h ������ ��-�� ������������� ��������

//������� ������
template <typename T>
class Element {
private:
    T object; //��� ������
    Element<T>* nextNode = nullptr; //��������� �� ��������� �������
public:
    Element(const T& obj) : object(obj) {}
	~Element() { delete nextNode; }

	void push(const T& obj)
	{
        //���� ��������� ������� ��� ����������, �� �������� ��� ������
        if (nextNode)
        {
            nextNode->push(obj);
        }
        //����� ������� ����� �������
        else
        {
            nextNode = new Element<T>(obj);
        }
	}

	T* get() //�������� ������
    {
        return &object;
    }

    Element<T>* next() //�������� ��������� �������
    {
		return nextNode;
    }

    //��������� �������� ��������� �� ��������� ����.
    void setNext(Element<T>* next) 
    {
        nextNode = next;
    }
};