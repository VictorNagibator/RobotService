#pragma once
#include "CellularChannel.h"

//����� ����� ��� 4G
class LTEChannel : public CellularChannel {
public:
    void connect() override;
    void transmit(const std::string& message) override;
    void disconnect() override;
};