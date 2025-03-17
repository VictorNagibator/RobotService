#include "CommunicationTimestampDecorator.h"
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

std::string CommunicationTimestampDecorator::getTimestamp() 
{
    //Получаем текущее время из системы
    auto now = std::chrono::system_clock::now();
    //Преобразуем время в std::time_t
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm local_tm;

    localtime_s(&local_tm, &now_time);

    //Форматируем время в строку "YYYY-MM-DD HH:MM:SS"
    std::ostringstream oss;
    oss << std::put_time(&local_tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void CommunicationTimestampDecorator::sendData(const std::string& data)
{
    //Добавляем метку времени к данным
    std::string timestampedData = "[" + getTimestamp() + "] " + data;
    wrappedComm->sendData(timestampedData);
}