#pragma once
#include "IEngine.h"
#include "IPowerSource.h"
#include "ICommunication.h"
#include "INavigation.h"

//��������� ������
class IRobot {
protected:
    int robotID; //���������� ����� ������
    std::string modelName; //�������� ������
    IEngine* engine;
    INavigation* navigation;
    ICommunication* communication;
    IPowerSource* powerSource;
public:
    IRobot(int id, const std::string& model, IEngine* engine,
        INavigation* nav, ICommunication* comm, IPowerSource* power);

    virtual void startDelivery(const std::string& destination) = 0; //������ ��������
    virtual void stopDelivery() = 0; //��������� ��������
    virtual void checkStatus() = 0; //������ ��������� ������
};
