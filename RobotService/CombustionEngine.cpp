#include "CombustionEngine.h"
#include <iostream>

void CombustionEngine::start() {
    currentRPM = RPMonInitial;
    environment->interact();
    std::cout << "ƒвигатель внутреннего сгорани€ " << engineName
        << " заводитс€. (ќбороты: " << currentRPM
        << " / " << maxRPM << "; " 
        << "сопротивление среды: " << environment->getResistance()
        << ").\n";
}

void CombustionEngine::stop() {
    currentRPM = 0; //ќбороты обнул€ютс€ после того, как глушим двигатель
    environment->interact();
    std::cout << "ƒвигатель внутреннего сгорани€ " << engineName << " останавливает работу.\n";
}

CombustionEngine* CombustionEngine::clone() const
{
	return new CombustionEngine(*this);
}