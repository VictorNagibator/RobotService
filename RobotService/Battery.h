#pragma once
#include "IPowerSource.h"

class Battery : public IPowerSource {
private:
    int capacity; //®мкость батареи в мјч
    double currentCharge = 0; //“екущий зар€д в мјч
public:
    Battery(int capacity, IEnvironment* environment);

    //¬озвращает оставшийс€ зар€д в процентах.
    double getCharge() const override;
    //ѕерезар€жаетс€ до полного зар€да.
    void recharge() override;
    //–азр€д батареи на определЄнное количество мјч
    void consume(double usage) override;
};
