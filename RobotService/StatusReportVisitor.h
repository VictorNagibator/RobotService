#pragma once
#include "IComponentVisitor.h"
#include <sstream>

//Сборщик отчёта по состоянию компонентов
class StatusReportVisitor : public IComponentVisitor {
    std::ostringstream oss;
public:
    void visit(const IEngine& e) override;
    void visit(const INavigation& n) override;
    void visit(const ICommunication& c) override;
    void visit(const IPowerSource& p) override;

    //Возвращает накопленный отчёт
    std::string getReport() const;
};
