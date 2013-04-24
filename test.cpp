#include <iostream>
#include "ezwin.h" 
using namespace std;
#include "bitmap.h"
int k;int flag1;
SimpleWindow w("My first window",29.8,21.5,Position(0.0,0.0));
BitMap Photo(w);
int ApiMain() {
	
	w.Open();
	BitMap Photo(w);
	Photo.Load("Game_Board.xpm");
	Position WindowCenter=w.GetCenter();
	Position PhotoPosition= WindowCenter+(-0.5*Photo.GetWidth(),-0.5*Photo.GetHeight());
	Photo.SetPosition(PhotoPosition);
	Photo.Draw();
	cout<<"K="<<endl;	
	cin>>k;
	
  
	
	cout<<"K="<<endl;
	w.Close();
	return 0;
}

