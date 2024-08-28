#include "Quackable.h"
#include <iostream>

Observable::Observable(QuackObservable* duck) : duck{duck}
{
}

void Observable::registerObserver(Observer* observer)
{
	obeservers.push_back(observer);
}

void Observable::notifyObservers()
{
	for (const auto& observer : obeservers) {
		observer->update(duck.get());
	}
}

void Quackologist::update(QuackObservable* duck)
{
	// 입출력 연산자 오버로딩 필요
	std::cout << "꽥꽥학자: " << duck << "가 방금 소리냈다.\n";
}
