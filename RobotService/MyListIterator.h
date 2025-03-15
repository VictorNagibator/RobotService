#pragma once
#include "Iterator.h"
#include "Element.h"

//���������� ��������
template <typename T>
class MyListIterator : public Iterator<T>
{
private:
    Element<T>* current; //������� ���� ������
    Element<T>* root; //���������� ������ ��� ������ ���������
public:
    MyListIterator(Element<T>* node) : current(node), root(node) {}

    bool hasNext() const 
    {
        return current != nullptr;
    }

    T* next()
    {
        if (!hasNext()) {
            throw std::exception("�������� ������ ����� ���������!");
        }
        
        T* data = current->get(); //���� ������ �������� ����
        current = current->next(); //��������� � ����������
        return data;
    }

    void reset()
    {
        current = root; //������ ���������� �� �����
    }
};