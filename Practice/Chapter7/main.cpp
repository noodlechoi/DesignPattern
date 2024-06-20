#include "Duck.h"

void testDuck(Duck* duck)
{
	duck->quack();
	duck->fly();
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
}