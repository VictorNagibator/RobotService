#pragma once
#include "ICellularChannel.h"

//����� ����� ��� 4G
class LTEChannel : public ICellularChannel {
public:
    void connect() override;
    void transmit(const std::string& message) override;
    void disconnect() override;
};