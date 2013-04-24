#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "ezwin.h"
#include "rect.h"
#include "ray.h" 
using namespace std;
#include "bitmap.h"
SimpleWindow w("MONOPOLY",28.8,21.5,Position(0.0,0.0));

int ApiMain() {
	char tchar;
	w.Open();
Position p0=w.GetCenter();
	 w.RenderLine(p0,p0,
		      Red,0.1);
cin>>tchar;
w.Close();
return 0;
}
