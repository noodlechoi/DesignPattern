#pragma once
#include "Amplifier.h"
#include "StreamingPlayer.h"
#include "Projector.h"
#include "TheaterLights.h"
#include "Screen.h"
#include "PopcornPopper.h"
#include <string>

class HomeTheaterFacade
{
	Amplifier* amp;
	StreamingPlayer* player;
	Projector* projector;
	TheaterLights* lights;
	Screen* screen;
	PopcornPopper* popper;

public:
	HomeTheaterFacade(Amplifier* amp, 
		StreamingPlayer* player,
		Projector* projector,
		TheaterLights* lights,
		Screen* screen,
		PopcornPopper* popper) : amp{amp}, player{player}, projector{projector}, lights{ lights }, screen{screen}, popper{ popper } {}

	void watchMovie(string movie)
	{
		cout << "영화 볼 준비 중" << endl;
		popper->on();
		popper->pop();
		lights->dim(10);
		screen->down();
		projector->on();
		amp->setStreamingPlayer(player);
		amp->setSurroundSound();
		amp->setVolume(5);
		player->on();
		player->play(movie);
	}
};

