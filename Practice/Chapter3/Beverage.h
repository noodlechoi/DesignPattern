#pragma once
#include <string>

class Beverage	// �߻� Ŭ����, �������̽� Ŭ������ ���� �������
{
protected:
	std::string desctiption{ "���� ����" };
public:
	virtual std::string getDescription();
	virtual double cost() = 0;
};

