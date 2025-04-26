#pragma once

class IEngine;
class INavigation;
class ICommunication;
class IPowerSource;

//Интерфейс посетителя для компонентов робота
class IComponentVisitor {
public:
    virtual void visit(const IEngine& eng) = 0;
    virtual void visit(const INavigation& nav) = 0;
    virtual void visit(const ICommunication& comm) = 0;
    virtual void visit(const IPowerSource& pow) = 0;
};