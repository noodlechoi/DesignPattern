// #include "Duck.h"

/*void testDuck(Duck* duck)
{
	duck->quack();
	duck->fly();
}

void testTurkey(Turkey* turkey)
{
	turkey->gobble();
	turkey->fly();
}
*/
#include "HomeTheaterFacade.h"

int main()
{
	// 어댑터 패턴
	/*Duck* duck = new MallarDuck;

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
	testTurkey(duckAdapter);*/

	// 퍼사드 패턴
	Amplifier* amplifier = new Amplifier;
	StreamingPlayer* player = new StreamingPlayer;
	Projector* projector = new Projector;
	TheaterLights* lights = new TheaterLights;
	Screen* screen = new Screen;
	PopcornPopper* popper = new PopcornPopper;

	HomeTheaterFacade* home = new HomeTheaterFacade(amplifier, player, projector, lights, screen, popper);

	home->watchMovie("인터스텔라");
}