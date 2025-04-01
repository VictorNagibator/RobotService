#include "ElectricMotor.h"
#include <iostream>

void ElectricMotor::start() {
    currentRPM = RPMonInitial; //Ёлектродвигатель мгновенно достигает высоких оборотов
    environment->interact();
    std::cout << "Ёлектромотор " << engineName
        << " заводитс€. (ќбороты: " << currentRPM
        << " / " << maxRPM << "; " 
        << "сопротивление среды: " << environment->getResistance() 
        << ").\n";
}

void ElectricMotor::stop() {
    currentRPM = 0; //ќбороты обнул€ютс€ после того, как глушим двигатель
    environment->interact();
    std::cout << "Ёлектромотор " << engineName << " останавливает работу.\n";
}