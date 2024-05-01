#pragma once
#include <string>

class Beverage	// �߻� Ŭ����, �������̽� Ŭ������ ���� �������
{
public:
	enum SIZE { TALL, GRANDE, VENTI };
protected:
	SIZE size{ Beverage::SIZE::TALL };
	std::string desctiption{ "���� ����" };
public:
	virtual std::string getDescription();
	virtual double cost() = 0;
	void setSize(SIZE size) { this->size = size; }
	virtual SIZE getSize() { return this->size; }
};

