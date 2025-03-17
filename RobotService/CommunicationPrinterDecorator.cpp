#include "CommunicationPrinterDecorator.h"
#include <iostream>

//��������������� ����� ��� ������ ��������� �� �����.
void CommunicationPrinterDecorator::printOnScreen(std::string data) 
{
    std::cout << "[����� ������] " << data << std::endl;
}

//����� �������������� ������ ��������� �������, ��������� ���������
void CommunicationPrinterDecorator::establishConnection() 
{
    printOnScreen("�����������...");
    //���������� ����� �������� ���������� (�, ��������������, ��������� �������)
    CommunicationDecorator::establishConnection();
    printOnScreen("���������� �����������!");
}

//������� ��������� ���������, ����� ������������ ��������
void CommunicationPrinterDecorator::sendData(const std::string& data) {
    printOnScreen("��������� ������...");
    CommunicationDecorator::sendData(data);
}

//����� ������� ��������� ���������, ����� ���������� ������� ��������� � ������������
std::string CommunicationPrinterDecorator::receiveCommand() {
    printOnScreen("������� �������...");
    std::string cmd = CommunicationDecorator::receiveCommand();
    printOnScreen("������� ��������.");
    return cmd;
}