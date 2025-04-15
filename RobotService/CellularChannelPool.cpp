#include "CellularChannelPool.h"

CellularChannelPool::CellularChannelPool(int initialSize)
{
    //��� ������� ������� �������� ������� 4G, �������� 3G
    //� �������� ����� ��� ����� ���������������� ��������, ������� ���� � ���������� ����� �����

    for (int i = 0; i < initialSize / 2; ++i) {
        ICellularChannel* ch = new LTEChannel();
        pool.push(ch);
    }

    for (int i = initialSize / 2; i < initialSize; ++i) {
        ICellularChannel* ch = new HSPAChannel();
        pool.push(ch);
    }
}

//���������� ��� ������������ ��������
CellularChannelPool::~CellularChannelPool() {
    while (!pool.empty()) {
        delete pool.front();
        pool.pop();
    }
}

//�������� ����� �� ����; ���� ��� ����, ���������� ������� ���������
ICellularChannel* CellularChannelPool::acquire() {
    if (pool.empty()) {
        std::cout << "[��� ������� ��������� �����] ��� ��������� �������!\n";
        return nullptr;
    }
    else {
		//���� ���� ��������� ������, ����� ���� �� ����
        ICellularChannel* ch = pool.front();
        pool.pop();
        return ch;
    }
}

//���������� ����� ������� � ���
void CellularChannelPool::release(ICellularChannel* ch) {
    pool.push(ch);
}