#pragma once
#include "CommunicationChannel.h"

//����� ����� ��� LTE (����� ������ 8-10 �� ����� �����)
class LTEChannel : public CommunicationChannel {
public:
    void connect() override;
    void transmit(const std::string& message) override;
    void disconnect() override;
};