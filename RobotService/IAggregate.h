#pragma once
#include "Iterator.h"

//��������� �������� (���������� ��������)
template <typename T>
class IAggregate {
public:
    virtual void push(const T& obj) = 0; //��������� ������
	virtual void remove(const T& obj) = 0; //������� ������
	virtual Iterator<T>* begin() = 0; //���������� �������� �� ������ ����������
    virtual Iterator<T>* end() = 0; //���������� �������� �� ����� ����������
};