#pragma once
#include "IComponentVisitor.h"

//Интерфейс для классов, которые могут быть посещены
class Visitable
{
public:
	virtual void accept(IComponentVisitor& v) const = 0;
};