#pragma once
#include <string>

class Beverage	// 추상 클래스, 인터페이스 클래스로 만들어도 상관없음
{
protected:
	std::string desctiption{ "제목 없음" };
public:
	virtual std::string getDescription();
	virtual double cost() = 0;
};

