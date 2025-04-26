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
    //Исправляем кодировку консоли для корректного отображения кириллицы
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Создаем роботов
    StandartGroundRobotFactory factory;
	IRobot* robotA = factory.createRobot(1, "Робот А");
    IRobot* robotB = factory.createRobot(2, "Робот B");

    //Паттерн состояние:
    robotA->wait();
    robotA->execute();
    robotA->startCharging();
    robotA->execute();
    robotA->runDiagnostics(); //Тут работает цепочка обязанностей
    robotA->execute();

    std::cout << "\n";

    //Добавляем их в центральный контроллер (паттерн Observer)
    CentralController* controller = CentralController::getInstance();
    controller->addRobot(robotA);
    controller->addRobot(robotB);

    controller->monitorRobots(); //Покажем состояние роботов

    //Сохраняем состояние
    ControllerSnapshot* snapshot = controller->saveState();

    //Затем изменяем
    controller->dispatchDelivery("пр. Ленина, 10", robotA);
    controller->removeRobot(robotB); //Удаляем робота B
    
	controller->monitorRobots(); //Покажем состояние роботов

	//Восстанавливаем состояние
	std::cout << "\n--- Восстановление состояния ---\n";
    controller->restoreState(snapshot);
    delete snapshot;
	controller->monitorRobots(); //Покажем изначальное состояние

    //Паттерн команда
	IPaymentProcessor* proc = new CreditCardProcessor();

    CoffeeVendingMachine* coffee = new CoffeeVendingMachine(proc);
    coffee->addItem(101, "Эспрессо", 50.0, 5);

    ParcelLocker* parcel = new ParcelLocker(proc);
    parcel->addItem(202, "Коробка#202", 120.0, 2);

    std::cout << "\n--- Доставка кофе ---\n";
    robotA->startDelivery("ул. Ленина, 10", "Кофейня", 101, coffee);
    robotA->execute();

    std::cout << "\n--- Доставка посылки ---\n";
    robotB->startDelivery("пр. Космонавтов, 5", "Постамат", 202, parcel);
    robotA->execute();

    //VISITOR — сбор статистики по компонентам
    std::cout << "\n--- Статистика по роботу ---\n";
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