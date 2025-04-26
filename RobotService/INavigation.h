#pragma once
#include <string>
#include "IEnvironment.h"
#include "Prototype.h"
#include "Visitable.h"

//����������� ����� ������������� �������
class INavigation : public Prototype, public Visitable {
protected:
    IEnvironment* environment;
    double x, y; //���������� ������
public:
    INavigation(IEnvironment* environment, double startX = 0, double startY = 0);

    //��������� �� �������� � �������� �����
    virtual void navigate(const std::string& destination) = 0;
    //���������� ��������� ������
    virtual void updatePosition(double newX, double newY);
    //��������� �������� ��� ������������� �����������
    virtual void adjustRoute() = 0;
    
    //�������� ������� ���������
	virtual bool selfTest() const = 0;

    //����� �������� �����
    virtual void setEnvironment(IEnvironment* env);
    IEnvironment* getEnvironment() const;

	//�������� ���������� ������
    double getX() const;
    double getY() const;

	virtual INavigation* clone() const = 0;

    virtual void accept(IComponentVisitor& v) const override;
};