#pragma once

//�������� ������
class IPrototypeRobot
{
public:
	virtual IPrototypeRobot* clone() const = 0;
};