#pragma once
#include <string>
#include "IEnvironment.h"
#include "Prototype.h"
#include "Visitable.h"

//����������� ����� ��� ������� �����
class ICommunication : public Prototype, public Visitable {
protected:
    IEnvironment* environment; //�����, � ������� �������� �������� �����
    int signalStrength; //���� �������
public:
    ICommunication(int signalStrength, IEnvironment* env);

    //������������ ����� � ����������� ������������
    virtual void establishConnection() = 0;
	//���������� �� ����
	virtual void disconnect() = 0;
    //�������� ������ � ��������� ������
    virtual void sendData(const std::string& data) = 0;
    //���� ����������� ������ �� ������������ �����������
    virtual std::string receiveCommand() = 0;
    
	//��������� ���� �������
	virtual int getSignalStrength() const;
    virtual IEnvironment* getEnvironment() const;

	//����� �������� ����� (��������, ����� ����� ��� ������ ��� ������� ������ ������������)
	virtual void setEnvironment(IEnvironment* env);

	virtual ICommunication* clone() const = 0;

    virtual void accept(IComponentVisitor& v) const override;
};