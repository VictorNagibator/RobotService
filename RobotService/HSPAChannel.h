#pragma once
#include "CellularChannel.h"

//����� ����� ��� 3G
class HSPAChannel : public CellularChannel
{
public:
    void connect() override;
    void transmit(const std::string& message) override;
    void disconnect() override;
};