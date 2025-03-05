#pragma once
#include "IRobot.h"

//�������� �����: ������������ ��� �������� �� ��������� ������ � ���������.
class GroundRobot : public IRobot {
public:
    void startDelivery(const std::string& destination) override;
    void stopDelivery() override;
    void updateStatus() override;
};