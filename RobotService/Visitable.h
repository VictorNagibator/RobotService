#pragma once
#include "IComponentVisitor.h"

//��������� ��� �������, ������� ����� ���� ��������
class Visitable
{
public:
	virtual void accept(IComponentVisitor& v) const = 0;
};