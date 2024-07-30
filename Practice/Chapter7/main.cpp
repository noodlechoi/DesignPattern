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
	// ����� ����
	/*Duck* duck = new MallarDuck;

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
	testTurkey(duckAdapter);*/

	// �ۻ�� ����
	Amplifier* amplifier = new Amplifier;
	StreamingPlayer* player = new StreamingPlayer;
	Projector* projector = new Projector;
	TheaterLights* lights = new TheaterLights;
	Screen* screen = new Screen;
	PopcornPopper* popper = new PopcornPopper;

	HomeTheaterFacade* home = new HomeTheaterFacade(amplifier, player, projector, lights, screen, popper);

	home->watchMovie("���ͽ��ڶ�");
}