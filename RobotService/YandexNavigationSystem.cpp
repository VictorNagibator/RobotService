#include "YandexNavigationSystem.h"

void YandexNavigationSystem::navigateOnRoute(const std::string& destination)
{
    std::cout << "—истема навигации яндекс: с помощью умных сервисов яндекса анализирую маршрут до " << destination << ".\n";
}

void YandexNavigationSystem::updateCoords(double newX, double newY)
{
    std::cout << "—истема навигации яндекс: обновл€ю координаты (" << newX << ", " << newY << ").\n";
}

void YandexNavigationSystem::reAdjust()
{
    std::cout << "—истема навигации яндекс: обновл€ю маршрут из-за преп€тствий...\n";
}