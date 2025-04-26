#include "DiagnosticHandler.h"

void DiagnosticHandler::setNext(DiagnosticHandler* next)
{
	this->next = next; //Устанавливаем следующий обработчик
}

//Возвращает true, если все проверки прошли успешно
bool DiagnosticHandler::handle(const IRobot& robot) 
{
    if (next) return next->handle(robot);
    return true;
}