#pragma once
#include <iostream>
#include <windows.h>

#include "StandartGroundRobotFactory.h"
#include "CoffeeVendingMachine.h"
#include "ParcelLocker.h"
#include "TicketKiosk.h"
#include "CreditCardProcessor.h"

int main() {
    //Исправляем кодировку консоли для корректного отображения кириллицы
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    StandartGroundRobotFactory factory;
	IRobot* robot = factory.createRobot(1, "Робот-курьер");



	IPaymentProcessor* paymentProcessor = new CreditCardProcessor();

    //Настраиваем автоматы
    CoffeeVendingMachine* coffee = new CoffeeVendingMachine(paymentProcessor);
    coffee->addItem(101, "Эспрессо", 50.0, 10);

    ParcelLocker* parcel = new ParcelLocker(paymentProcessor);
    parcel->addItem(202, "Коробка 202", 120.0, 2);

    TicketKiosk* kiosk = new TicketKiosk(paymentProcessor);
    kiosk->addItem(303, "Билет на фильм Майнкрафт", 200.0, 5);

    //Демонстрация
    robot->startDelivery("ул. Ленина, 10", "Кофейня", 101, coffee);
    robot->execute();
    robot->wait();
	std::cout << std::endl;
    robot->startDelivery("ул. Пушкина, 5", "Постамат", 202, parcel);
	robot->execute();
    robot->wait();
    std::cout << std::endl;
    robot->startDelivery("ул. Мира, 1", "Киоск", 303, kiosk);
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