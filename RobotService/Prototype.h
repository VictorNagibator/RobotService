#pragma once

//��������� ���������
//������������ ���������� � ���������� ���� ������ ������ - clone()
class Prototype
{
public:
	virtual Prototype* clone() const = 0;
};