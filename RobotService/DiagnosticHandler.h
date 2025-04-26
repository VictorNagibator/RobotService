#pragma once
#include "IRobot.h"

//��������� ����� ������� ����������� ������
class DiagnosticHandler {
protected:
	DiagnosticHandler* next; //��������� �� ��������� ����� ������� �����������
public:
    DiagnosticHandler() : next(nullptr) {}

	void setNext(DiagnosticHandler* next); //��������� ��������� ����� ������� �����������
	virtual bool handle(const IRobot& robot); //��������� �����������
};