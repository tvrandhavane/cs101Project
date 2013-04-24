#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "ezwin.h" 
using namespace std;
#include "bitmap.h"
SimpleWindow w("M1",24.0,16.0,Position(0.0,0.0));
BitMap Exit_Button(w);
BitMap Play_Button(w);
int MouseClickCallBackEvent(const Position &MousePosition)
	{
		if(Exit_Button.IsInside(MousePosition))
		{
			w.Close();
		}
		else if(Play_Button.IsInside(MousePosition))
		{
			w.Close();
		}	
		return 1;
	}
int ApiMain() {	
	w.Open();	
	Exit_Button.Load("Exit.xpm");
	Play_Button.Load("Play.xpm");
	Position Play_ButtonPosition= Position(0.0,13.0);
	Position Exit_ButtonPosition= Position(20.0,13.0);
	Exit_Button.SetPosition(Exit_ButtonPosition);
	Exit_Button.Draw();
	Play_Button.SetPosition(Play_ButtonPosition);
	Play_Button.Draw();
	w.SetMouseClickCallback(MouseClickCallBackEvent);
        return 0;
}

