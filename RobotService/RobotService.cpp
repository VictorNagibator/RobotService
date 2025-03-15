#include <iostream>
#include <windows.h>
#include "ElectricMotor.h"
#include "ProxyEngine.h"
#include "GPSNavigation.h"
#include "WiFiCommunication.h"
#include "Battery.h"
#include "GroundRobot.h"
#include "CombustionEngine.h"
#include "VisionNavigation.h"
#include "LTECommunication.h"
#include "FuelCell.h"
#include "Drone.h"
#include "CentralController.h"
#include "MyList.h"
#include "ProxyIterator.h"

int main() {
	//Исправляем кодировку консоли для корректного отображения кириллицы
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    MyList<int> list;

    list.push(1);
    list.push(4);
    list.push(6); 
    list.push(2);

    auto it = ProxyIterator<int>(list.begin());

    std::cout << "Обход списка:\n";
    while (it.hasNext()) {
        std::cout << *it.next() << " ";
    }
    std::cout << std::endl;

    it.reset();
    std::cout << "Повторный обход списка:\n";
    while (it.hasNext()) {
        std::cout << *it.next() << " ";
    }
    std::cout << std::endl;

    return 0;
}