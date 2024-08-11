#include "DinnerMenu.h"
#include "DinnerMenuIterator.h"
#include <iostream>

DinnerMenu::DinnerMenu()
{
	menuItems = new MenuItem*[MAX_ITEMS];

	addItem("ä�������ڿ� BLT", "��� ���� ���� ������, ����, �丶�並 ���� �޴�", true, 2.99);
	addItem("BLT", "��� ���� ������, ����, �丶�並 ���� �޴�", false, 2.99);
	addItem("������ ����", "���� �����带 ����� ������ ����", false, 3.29);
	addItem("�ֵ���", "���ũ���Ʈ, ���� ���, ����, ġ� ��鿩�� �ֵ���", false, 3.05);
}

void DinnerMenu::addItem(std::string name, std::string description, bool vegetarian, double price)
{
	MenuItem* menuItem = new MenuItem(name, description, vegetarian, price);
	if (numberOfItems >= MAX_ITEMS) {
		std::cout << "�޴��� ���� á���ϴ�." << std::endl;
	}
	else {
		menuItems[numberOfItems] = menuItem;
		numberOfItems++;
	}
}

Iterator* DinnerMenu::createIterator()
{
	return new DinnerMenuIterator(menuItems);
}

//MenuItem** DinnerMenu::getMenuItems()
//{
//	return menuItems;
//}
