#include "HybridEngine.h"
#include <iostream>

void HybridEngine::start() {
    currentRPM = RPMonInitial;
    std::cout << "√ибридный двигатель " << engineName
        << " заводитс€. (ќбороты: " << currentRPM
        << " / " << maxRPM << ")\n";
}

void HybridEngine::stop() {
    currentRPM = 0; //ќбороты обнул€ютс€ после того, как глушим двигатель
    std::cout << "√ибридный двигатель " << engineName << " останавливает работу.\n";
}