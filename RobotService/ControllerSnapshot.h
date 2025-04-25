#pragma once
#include <vector>
#include <iostream>
#include "IRobot.h"
#include "IAggregate.h"

//Снимок состояния контроллера
class ControllerSnapshot {
private:
    //Закрытые члены доступны только контроллеры
    friend class IController;

    //Поля контроллера
    std::string name;
    IAggregate<IRobot*>* robots;

    ControllerSnapshot(
        std::string name,
        IAggregate<IRobot*>* robots
    ) : robots(robots), name(name) {}
};