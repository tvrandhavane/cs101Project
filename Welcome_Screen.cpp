#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "ezwin.h" 
using namespace std;
#include "bitmap.h"

SimpleWindow w("Welcome To Monopoly",25.0,19.5,Position(0.0,0.0));
BitMap Exit_Button(w);
BitMap Play_Button(w);
BitMap Welcome(w);
BitMap imagee(w);


int ApiMain() {
	char a;
	w.Open();	
	Exit_Button.Load("dice.xpm");
	Play_Button.Load("df.xpm");
	Welcome.Load("diceno1.xpm");
        imagee.Load("diceno2.xpm");
	Position WindowCenter=w.GetCenter();
	Position Play_ButtonPosition=WindowCenter+Position(-0.5*Play_Button.GetWidth(),-0.5*Play_Button.GetHeight());
	//Position Exit_ButtonPosition= Position(12.0+Exit_Button.GetWidth(),17-Exit_Button.GetHeight());
	Position WelcomePosition= WindowCenter+Position(3.0-0.5*Welcome.GetWidth(),4.0-0.5*Welcome.GetHeight());
	Position imageePosition= WelcomePosition+Position(3.0,0.0);	
	Play_Button.SetPosition(Play_ButtonPosition);
	Play_Button.Draw();
	//Exit_Button.SetPosition(Exit_ButtonPosition);
	//Exit_Button.Draw();
	Welcome.SetPosition(WelcomePosition);
	Welcome.Draw();
	imagee.SetPosition(imageePosition);
	imagee.Draw();
	cin>>a;
	w.Close();
        return 0;
}

