#pragma once
#include <iostream>
#include <windows.h>

#include "StandartGroundRobotFactory.h"
#include "CoffeeVendingMachine.h"
#include "ParcelLocker.h"
#include "TicketKiosk.h"
#include "CreditCardProcessor.h"

int main() {
    //���������� ��������� ������� ��� ����������� ����������� ���������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    StandartGroundRobotFactory factory;
	IRobot* robot = factory.createRobot(1, "�����-������");



	IPaymentProcessor* paymentProcessor = new CreditCardProcessor();

    //����������� ��������
    CoffeeVendingMachine* coffee = new CoffeeVendingMachine(paymentProcessor);
    coffee->addItem(101, "��������", 50.0, 10);

    ParcelLocker* parcel = new ParcelLocker(paymentProcessor);
    parcel->addItem(202, "������� 202", 120.0, 2);

    TicketKiosk* kiosk = new TicketKiosk(paymentProcessor);
    kiosk->addItem(303, "����� �� ����� ���������", 200.0, 5);

    //������������
    robot->startDelivery("��. ������, 10", "�������", 101, coffee);
    robot->execute();
    robot->wait();
	std::cout << std::endl;
    robot->startDelivery("��. �������, 5", "��������", 202, parcel);
	robot->execute();
    robot->wait();
    std::cout << std::endl;
    robot->startDelivery("��. ����, 1", "�����", 303, kiosk);
	robot->execute();
    robot->wait();
    std::cout << std::endl;

    robot->runDiagnostics();
    robot->execute();

    delete robot;
    delete coffee;
    delete parcel;
    delete kiosk;
    return 0;

    return 0;
}