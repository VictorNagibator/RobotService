#pragma once

//��������� ���������
template <typename T>
class Iterator {
public:
    virtual bool hasNext() const = 0; //���������, ���� �� ��������� �������
    virtual T* next() = 0; //���������� ������ �������� �������� � ��������� � ����������
    virtual void reset() = 0; //���������� �������� � ������
};