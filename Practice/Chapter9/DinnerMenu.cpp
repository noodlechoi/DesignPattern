#include "DinnerMenu.h"
#include "DinnerMenuIterator.h"
#include <iostream>

DinnerMenu::DinnerMenu()
{
	menuItems = new MenuItem*[MAX_ITEMS];

	addItem("채식주의자용 BLT", "통밀 위에 콩고기 베이컨, 상추, 토마토를 얹은 메뉴", true, 2.99);
	addItem("BLT", "통밀 위에 베이컨, 상추, 토마토를 얹은 메뉴", false, 2.99);
	addItem("오늘의 스프", "감자 샐러드를 곁들인 오늘의 스프", false, 3.29);
	addItem("핫도그", "사워크라우트, 갖은 양념, 양파, 치즈가 곁들여진 핫도그", false, 3.05);
}

void DinnerMenu::addItem(std::string name, std::string description, bool vegetarian, double price)
{
	MenuItem* menuItem = new MenuItem(name, description, vegetarian, price);
	if (numberOfItems >= MAX_ITEMS) {
		std::cout << "메뉴가 가득 찼습니다." << std::endl;
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
