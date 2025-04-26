#pragma once
#include "IComponentVisitor.h"
#include <sstream>

//������� ������ �� ��������� �����������
class StatusReportVisitor : public IComponentVisitor {
    std::ostringstream oss;
public:
    void visit(const IEngine& e) override;
    void visit(const INavigation& n) override;
    void visit(const ICommunication& c) override;
    void visit(const IPowerSource& p) override;

    //���������� ����������� �����
    std::string getReport() const;
};
