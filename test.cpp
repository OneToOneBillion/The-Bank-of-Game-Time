#include"PersonalInfo.h"
#include"Bank.h"
#include<iostream>

using namespace std;

int main()
{
	PersonalInfo *info1=new PersonalInfo();
	long int t = 40 * 60;
	info1->SetRGT(t);
	info1->InitDGT(t);
	cout << info1->GetRGT();
	Bank bank1;
	bank1.InitInfo(info1);
	
	system("pause");
	return 0;
}