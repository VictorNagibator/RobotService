#pragma once
#include "IRobot.h"

//�������� ����� (����): ������������ ��� ������� ��������, ������ ������� � �������� � ��������������� ������
class Drone : public IRobot {
public:
    Drone(int id, const std::string& model, IEngine* eng,
        INavigation* nav, ICommunication* comm, IPowerSource* power)
        : IRobot(id, model, eng, nav, comm, power) {}

    void checkStatus() override;

	void moveTo(const std::string& destination) override;

    Drone* clone() const override;
};