#include "CellularChannelPool.h"

CellularChannelPool::CellularChannelPool(int initialSize)
{
    //ƒл€ примера создаем половину каналов 4G, половину 3G
    //¬ реальной жизни пул будет инициазироватьс€ каналами, которые есть у конкретной вышки св€зи

    for (int i = 0; i < initialSize / 2; ++i) {
        CellularChannel* ch = new LTEChannel();
        pool.push(ch);
    }

    for (int i = initialSize / 2; i < initialSize; ++i) {
        CellularChannel* ch = new HSPAChannel();
        pool.push(ch);
    }
}

//ƒеструктор дл€ освобождени€ ресурсов
CellularChannelPool::~CellularChannelPool() {
    while (!pool.empty()) {
        delete pool.front();
        pool.pop();
    }
}

//ѕолучаем канал из пула; если пул пуст, необходимо вывести сообщение
CellularChannel* CellularChannelPool::acquire() {
    if (pool.empty()) {
        std::cout << "[ѕул каналов мобильной св€зи] Ќет доступных каналов!\n";
        return nullptr;
    }
    else {
		//≈сли есть доступные каналы, берем один из пула
        CellularChannel* ch = pool.front();
        pool.pop();
        return ch;
    }
}

//¬озвращаем канал обратно в пул
void CellularChannelPool::release(CellularChannel* ch) {
    pool.push(ch);
}