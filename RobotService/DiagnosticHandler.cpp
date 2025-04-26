#include "DiagnosticHandler.h"

void DiagnosticHandler::setNext(DiagnosticHandler* next)
{
	this->next = next; //������������� ��������� ����������
}

//���������� true, ���� ��� �������� ������ �������
bool DiagnosticHandler::handle(const IRobot& robot) 
{
    if (next) return next->handle(robot);
    return true;
}