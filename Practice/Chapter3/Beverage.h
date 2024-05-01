#pragma once
#include <string>

class Beverage	// 추상 클래스, 인터페이스 클래스로 만들어도 상관없음
{
public:
	enum SIZE { TALL, GRANDE, VENTI };
protected:
	SIZE size{ Beverage::SIZE::TALL };
	std::string desctiption{ "제목 없음" };
public:
	virtual std::string getDescription();
	virtual double cost() = 0;
	void setSize(SIZE size) { this->size = size; }
	virtual SIZE getSize() { return this->size; }
};

