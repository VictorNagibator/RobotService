#pragma once

//����������� �������� ��� ��������� �������
class IPrototypePowerSource
{
public:
	virtual IPrototypePowerSource* clone() const = 0;
};