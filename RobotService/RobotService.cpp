#pragma once
#include <iostream>
#include <windows.h>

#include "StandartGroundRobotFactory.h"
#include "CoffeeVendingMachine.h"
#include "ParcelLocker.h"
#include "TicketKiosk.h"
#include "CreditCardProcessor.h"
#include "CentralController.h"
#include "ControllerSnapshot.h"
#include "StatusReportVisitor.h"

int main() {
    //���������� ��������� ������� ��� ����������� ����������� ���������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //������� �������
    StandartGroundRobotFactory factory;
	IRobot* robotA = factory.createRobot(1, "����� �");
    IRobot* robotB = factory.createRobot(2, "����� B");

    //������� ���������:
    robotA->wait();
    robotA->execute();
    robotA->startCharging();
    robotA->execute();
    robotA->runDiagnostics(); //��� �������� ������� ������������
    robotA->execute();

    std::cout << "\n";

    //��������� �� � ����������� ���������� (������� Observer)
    CentralController* controller = CentralController::getInstance();
    controller->addRobot(robotA);
    controller->addRobot(robotB);

    controller->monitorRobots(); //������� ��������� �������

    //��������� ���������
    ControllerSnapshot* snapshot = controller->saveState();

    //����� ��������
    controller->dispatchDelivery("��. ������, 10", robotA);
    controller->removeRobot(robotB); //������� ������ B
    
	controller->monitorRobots(); //������� ��������� �������

	//��������������� ���������
	std::cout << "\n--- �������������� ��������� ---\n";
    controller->restoreState(snapshot);
    delete snapshot;
	controller->monitorRobots(); //������� ����������� ���������

    //������� �������
	IPaymentProcessor* proc = new CreditCardProcessor();

    CoffeeVendingMachine* coffee = new CoffeeVendingMachine(proc);
    coffee->addItem(101, "��������", 50.0, 5);

    ParcelLocker* parcel = new ParcelLocker(proc);
    parcel->addItem(202, "�������#202", 120.0, 2);

    std::cout << "\n--- �������� ���� ---\n";
    robotA->startDelivery("��. ������, 10", "�������", 101, coffee);
    robotA->execute();

    std::cout << "\n--- �������� ������� ---\n";
    robotB->startDelivery("��. �����������, 5", "��������", 202, parcel);
    robotA->execute();

    //VISITOR � ���� ���������� �� �����������
    std::cout << "\n--- ���������� �� ������ ---\n";
    StatusReportVisitor report;
    robotA->accept(report);
    std::cout << report.getReport();

    delete coffee;
    delete parcel;
    delete proc;

    delete controller; 
    delete robotA;
    delete robotB;

    return 0;
}