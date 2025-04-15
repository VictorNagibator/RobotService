#pragma once
#include "CellularChannel.h"
#include "LTEChannel.h"
#include "HSPAChannel.h"
#include <queue>
#include <iostream>

class CellularChannelPool
{
private:
    std::queue<CellularChannel*> pool;
public:
	// онструктор, который создает пул каналов заданного размера
    CellularChannelPool(int initialSize);

	//ƒеструктор дл€ освобождени€ ресурсов
    ~CellularChannelPool();

    //ѕолучаем канал из пула
    CellularChannel* acquire();

    //¬озвращаем канал обратно в пул
    void release(CellularChannel* ch);
};