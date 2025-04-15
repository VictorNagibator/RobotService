#pragma once
#include "ICellularChannel.h"
#include "LTEChannel.h"
#include "HSPAChannel.h"
#include <queue>
#include <iostream>

class CellularChannelPool
{
private:
    std::queue<ICellularChannel*> pool;
public:
	//�����������, ������� ������� ��� ������� ��������� �������
    CellularChannelPool(int initialSize);

	//���������� ��� ������������ ��������
    ~CellularChannelPool();

    //�������� ����� �� ����
    ICellularChannel* acquire();

    //���������� ����� ������� � ���
    void release(ICellularChannel* ch);
};