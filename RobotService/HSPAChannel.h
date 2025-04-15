#pragma once
#include "ICellularChannel.h"

//����� ����� ��� 3G
class HSPAChannel : public ICellularChannel
{
public:
    void connect() override;
    void transmit(const std::string& message) override;
    void disconnect() override;
};