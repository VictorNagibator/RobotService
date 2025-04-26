#include "StatusReportVisitor.h"
#include "IEngine.h"
#include "INavigation.h"
#include "ICommunication.h"
#include "IPowerSource.h"

void StatusReportVisitor::visit(const IEngine& e) 
{
    oss << "[Двигатель] Модель: " << e.getName()
        << ", Среда: " << e.getEnvironment()->getEnvironmentName()
        << ", Обороты: " << e.getRPM() << "/"
        << e.getMaxRPM()
        << ", Температура: " << e.getTemperature() << "/" << e.getTemperatureThreshold() << " °C\n";
}

void StatusReportVisitor::visit(const INavigation& n)
{
    oss << "[Навигация] Среда: " << n.getEnvironment()->getEnvironmentName()
        << ", Расположение: (" << n.getX() << "," << n.getY() << ")\n";
}

void StatusReportVisitor::visit(const ICommunication& c) 
{
    oss << "[Средство связи] Cреда: " << c.getEnvironment()->getEnvironmentName()
        << ", Сила сигнала: " << c.getSignalStrength()
        << "\n";
}

void StatusReportVisitor::visit(const IPowerSource& p) 
{
    oss << "[Система питания] Среда: " << p.getEnvironment()->getEnvironmentName()
        << ", Уровень заряда: " << p.getCharge() << "%\n";
}

//Возвращает накопленный отчёт
std::string StatusReportVisitor::getReport() const
{
    return oss.str();
}