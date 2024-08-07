#include "PancakeHouseMenu.h"

PancakeHouseMenu::PancakeHouseMenu()
{
	addItem("K&B ������ũ ��Ʈ", "��ũ���� ���׿� �佺Ʈ�� ��鿩�� ������ũ", true, 2.99);
	addItem("���ַ� ������ũ ��Ʈ", "�ް� �����̿� �ҽ����� ��鿩�� ������ũ", false, 2.99);
	addItem("��纣�� ������ũ ��Ʈ", "�ż��� ��纣���� ��纣�� �÷����� ���� ������ũ", true, 3.49);
	addItem("����", "���⿡ ���� ��纣���� ���⸦ ���� �� �ִ� ����", true, 3.59);
}

void PancakeHouseMenu::addItem(std::string name, std::string description, bool vegetarian, double price)
{
	auto menuItem = new MenuItem(name, description, vegetarian, price);
	menuItems.push_back(menuItem);
}

std::list<MenuItem*> PancakeHouseMenu::getMenuItems()
{
	return menuItems;
}
