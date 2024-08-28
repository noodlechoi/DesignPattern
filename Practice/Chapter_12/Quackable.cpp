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
	// ����� ������ �����ε� �ʿ�
	std::cout << "�в�����: " << duck << "�� ��� �Ҹ��´�.\n";
}
