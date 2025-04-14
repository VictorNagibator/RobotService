#include "IRobot.h"
#include "CommunicationEncryptorDecorator.h"

IRobot::IRobot(int id, const std::string& model, IEngine* eng,
    INavigation* nav, ICommunication* comm, IPowerSource* power)
{
    robotID = id;
    modelName = model;
    engine = eng;
    navigation = nav;
    communication = comm;
    powerSource = power;
}

const IEngine& IRobot::getEngine() const
{
	return *engine;
}

const INavigation& IRobot::getNavigation() const
{
	return *navigation;
}

const ICommunication& IRobot::getCommunication() const
{
	return *communication;
}

const IPowerSource& IRobot::getPowerSource() const
{
	return *powerSource;
}

