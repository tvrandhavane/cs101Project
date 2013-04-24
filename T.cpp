#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "ezwin.h" 
using namespace std;
#include "bitmap.h"
SimpleWindow w("MONOPOLY",29.8,21.5,Position(0.0,0.0));
BitMap Exit_Button(w);
BitMap Play_Button(w);
BitMap Welcome(w);
int ApiMain()
{
	w.Open();
	Exit_Button.Load("Exit.xpm");
	Play_Button.Load("Play.xpm");
	Welcome.Load("wel.xpm");
	Position Play_ButtonPosition= Position(0.0,w.GetHeight()-Play_Button.GetHeight());
	Position Exit_ButtonPosition= Position(w.GetWidth()-Exit_Button.GetWidth(),w.GetHeight()-Exit_Button.GetHeight());
	Position WelcomePosition=Position(0.5*(w.GetWidth()-Welcome.GetWidth()),0.0);
	Exit_Button.SetPosition(Exit_ButtonPosition);
	Exit_Button.Draw();
	Play_Button.SetPosition(Play_ButtonPosition);
	Play_Button.Draw();
	Welcome.SetPosition(WelcomePosition);
	Welcome.Draw();
	return 0;
}
