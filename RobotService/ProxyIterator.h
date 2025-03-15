#pragma once
#include "Iterator.h"

//������ �������� ��� ���������� ������� ������
template <typename T>
class ProxyIterator : public Iterator<T>
{
private:
	Iterator<T>* realIterator; //�������� ������ ���������
public:
	ProxyIterator(Iterator<T>* it) : realIterator(it) {}
	~ProxyIterator() { delete realIterator; } //������� �������� ��������

	//��� ��������� ������ ��������� �������� ������

	bool hasNext() const override
	{
		return realIterator->hasNext();
	}

	T* next() override
	{
		return realIterator->next();
	}

	void reset() override
	{
		realIterator->reset();
	}
};