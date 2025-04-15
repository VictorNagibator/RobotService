#pragma once
#include "IMapSegmentBuilder.h"

//��������� ��������� ��� ���������� �����
class IMapDirector
{
protected:
    IMapSegmentBuilder* builder; //����������� ������������ ������� �����������
public:
    IMapDirector(IMapSegmentBuilder* b) : builder(b) {}

	virtual MapSegment* constructMap() const = 0; //����� ��� ���������� �����
};