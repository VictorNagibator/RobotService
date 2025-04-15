#pragma once
#include "CommunicationChannel.h"

// анал св€зи дл€ LTE (таких обычно 8-10 на одной точке)
class LTEChannel : public CommunicationChannel {
public:
    void connect() override;
    void transmit(const std::string& message) override;
    void disconnect() override;
};