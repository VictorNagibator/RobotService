#include "HybridEngine.h"
#include <iostream>

void HybridEngine::start() {
    currentRPM = RPMonInitial;
    environment->interact();
    std::cout << "√ибридный двигатель " << engineName
        << " заводитс€. (ќбороты: " << currentRPM
        << " / " << maxRPM << "; " 
        << "сопротивление среды: " << environment->getResistance()
        << ").\n";
}

void HybridEngine::stop() {
    currentRPM = 0; //ќбороты обнул€ютс€ после того, как глушим двигатель
    environment->interact();
    std::cout << "√ибридный двигатель " << engineName << " останавливает работу.\n";
}