#pragma once

//јналогичный прототип дл€ источника питани€
class IPrototypePowerSource
{
public:
	virtual IPrototypePowerSource* clone() const = 0;
};