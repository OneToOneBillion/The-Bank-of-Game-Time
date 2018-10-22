#include"PersonalInfo.h"
#include"Bank.h"
#include<iostream>

using namespace std;

int main()
{
	PersonalInfo *info1=new PersonalInfo();
	long int t = 5;
	info1->SetRGT(t);
	info1->InitDGT(t);
	info1->SetDGT(t);
	cout << info1->GetRGT()<<endl;
	Bank bank1;
	bank1.InitInfo(info1);
	

	bank1.StartGame();

	bank1.EndGame();
	cout << info1->GetRGT() << endl;
	cout << info1->GetTGT() << endl;
	//Ê£ÏÂstartgameºÍstartstudyÎ´²âÊÔ
	system("pause");
	return 0;
}