#include <iostream>
#include <windows.h>
#include "Clock.h"

using namespace std;

void main()
{
	Clock countdown;
	int tag, h, m, s;
	cout << "input hour:"; 
	cin >> h;
	cout << "input minute:";
	cin >> m;
	cout << "input second:";
	cin >> s;
	cin >> tag;
	countdown.set(h, m, s);
	system("cls");
	if (tag == 0)
	{

		Clock *p = &countdown;
		countdown.Start(*p);
		cout << countdown.Getcounttime() - 1;

	}
		system("pause");
	}




