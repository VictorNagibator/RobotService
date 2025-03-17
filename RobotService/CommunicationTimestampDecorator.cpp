#include "CommunicationTimestampDecorator.h"
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

std::string CommunicationTimestampDecorator::getTimestamp() 
{
    //�������� ������� ����� �� �������
    auto now = std::chrono::system_clock::now();
    //����������� ����� � std::time_t
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm local_tm;

    localtime_s(&local_tm, &now_time);

    //����������� ����� � ������ "YYYY-MM-DD HH:MM:SS"
    std::ostringstream oss;
    oss << std::put_time(&local_tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void CommunicationTimestampDecorator::sendData(const std::string& data)
{
    //��������� ����� ������� � ������
    std::string timestampedData = "[" + getTimestamp() + "] " + data;
    wrappedComm->sendData(timestampedData);
}