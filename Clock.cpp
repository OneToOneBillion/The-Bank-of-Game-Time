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
	system("cls");
	if (tag == 0)
	{
		countdown.Start();

	}
		while (!countdown.GetIsStop())
		{
			if (!countdown.GetIsPause())
			{
				//���������ͣ����...

				countdown.set(h, m, s);
				countdown.show();
				Sleep(1000); 
				system("cls");
				s--;
				if (s == -1)
				{
					s = 59;
					m--;
					if (m == -1)
					{
						m = 59;
						h--;
						if (h == -1) //��ʱ����
						{
							countdown.Stop();
							cout << "time up!" << endl;
							break;
						}
					}
				}
			}
			else
			{
				//�����ͣ����
			}
		}
		system("pause");
	}



