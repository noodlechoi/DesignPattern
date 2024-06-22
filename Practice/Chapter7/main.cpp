#include "Duck.h"

void testDuck(Duck* duck)
{
	duck->quack();
	duck->fly();
}

void testTurkey(Turkey* turkey)
{
	turkey->gobble();
	turkey->fly();
}

int main()
{
	Duck* duck = new MallarDuck;

	Turkey* turkey = new WildTurkey;
	Duck* turkeyAdapter = new TurketAdapter(turkey);

	cout << "ĥ������ ���ϱ�" << endl;
	turkey->gobble();
	turkey->fly();

	cout << "\n������ ���ϱ�" << endl;
	testDuck(duck);

	cout << "\nĥ���� ����Ͱ� ���ϱ�" << endl;
	testDuck(turkeyAdapter);

	Turkey* duckAdapter = new DuckAdapter(duck);

	cout << "������ ���ϱ�" << endl;
	duck->quack();
	duck->fly();

	cout << "\nĥ������ ���ϱ�" << endl;
	testTurkey(turkey);

	cout << "\n���� ����Ͱ� ���ϱ�" << endl;
	testTurkey(duckAdapter);
}