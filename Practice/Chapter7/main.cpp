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

	cout << "칠면조가 말하길" << endl;
	turkey->gobble();
	turkey->fly();

	cout << "\n오리가 말하길" << endl;
	testDuck(duck);

	cout << "\n칠면조 어댑터가 말하길" << endl;
	testDuck(turkeyAdapter);

	Turkey* duckAdapter = new DuckAdapter(duck);

	cout << "오리가 말하길" << endl;
	duck->quack();
	duck->fly();

	cout << "\n칠면조가 말하길" << endl;
	testTurkey(turkey);

	cout << "\n오리 어댑터가 말하길" << endl;
	testTurkey(duckAdapter);
}