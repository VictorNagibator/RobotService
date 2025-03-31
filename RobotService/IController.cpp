#include "IController.h"

const IRobotExpert& IController::getRobotExpert() const
{
	return *expert;
}