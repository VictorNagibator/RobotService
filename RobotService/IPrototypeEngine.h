#pragma once

class IPrototypeEngine
{
public:
	virtual IPrototypeEngine* clone() const = 0; //����� ������������
};