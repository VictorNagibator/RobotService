#pragma once
#include <vector>
#include <iostream>
#include "IRobot.h"
#include "IAggregate.h"

//������ ��������� �����������
class ControllerSnapshot {
private:
    //�������� ����� �������� ������ �����������
    friend class IController;

    //���� �����������
    std::string name;
    IAggregate<IRobot*>* robots;

    ControllerSnapshot(
        std::string name,
        IAggregate<IRobot*>* robots
    ) : robots(robots), name(name) {}
};