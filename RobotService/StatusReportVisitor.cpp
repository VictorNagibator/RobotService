#include "StatusReportVisitor.h"
#include "IEngine.h"
#include "INavigation.h"
#include "ICommunication.h"
#include "IPowerSource.h"

void StatusReportVisitor::visit(const IEngine& e) 
{
    oss << "[���������] ������: " << e.getName()
        << ", �����: " << e.getEnvironment()->getEnvironmentName()
        << ", �������: " << e.getRPM() << "/"
        << e.getMaxRPM()
        << ", �����������: " << e.getTemperature() << "/" << e.getTemperatureThreshold() << " �C\n";
}

void StatusReportVisitor::visit(const INavigation& n)
{
    oss << "[���������] �����: " << n.getEnvironment()->getEnvironmentName()
        << ", ������������: (" << n.getX() << "," << n.getY() << ")\n";
}

void StatusReportVisitor::visit(const ICommunication& c) 
{
    oss << "[�������� �����] C����: " << c.getEnvironment()->getEnvironmentName()
        << ", ���� �������: " << c.getSignalStrength()
        << "\n";
}

void StatusReportVisitor::visit(const IPowerSource& p) 
{
    oss << "[������� �������] �����: " << p.getEnvironment()->getEnvironmentName()
        << ", ������� ������: " << p.getCharge() << "%\n";
}

//���������� ����������� �����
std::string StatusReportVisitor::getReport() const
{
    return oss.str();
}