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
	//�����������, ������� ������� ��� ������� ��������� �������
    CellularChannelPool(int initialSize);

	//���������� ��� ������������ ��������
    ~CellularChannelPool();

    //�������� ����� �� ����
    CellularChannel* acquire();

    //���������� ����� ������� � ���
    void release(CellularChannel* ch);
};