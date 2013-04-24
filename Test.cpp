#include "ezwin.h" 
using namespace std;
#include "bitmap.h"
SimpleWindow w("MONOPOLY",29.8,21.5,Position(0.0,0.0));
int ApiMain()
{
	char getchar;	
	w.Open();
	Position p1=w.GetCenter();
	cin>>getchar;
w.Close();
return 0;
}
