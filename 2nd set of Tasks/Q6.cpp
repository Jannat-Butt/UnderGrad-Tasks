#include<iostream>
#include"Q6.h"
using namespace std;
int main()
{
	Calender c1;
	int yr, month;
   int weeks;
   int d1, d2, m1, m2, y1, y2;
  int days;
	char input;
	cout << "......................Enter Year :..................."<<endl;
	cin >> yr;
	cout<<endl<< "......................Enter Month:..................."<<endl;
	cin >> month;
	c1.DisplayCalender(yr,month);
	cout << "................Enter 1st Date and Month and year 25.2.2022..........:" << endl;
	cin >> d1;
	cin >> m1;
	cin >> y1;
	cout << "................Enter 2nd Date and Month and year 2.03.20..........:" << endl;
	cin >> d2;
	cin >> m2;
	cin >> y2;
	Calender c2;
	c2.differenceofDates(d1, m1, y1,d2,m2,y2);
	cout << "................Enter starting Date and Month and year 25.2.2022..........:" << endl;
	cin >> d1;
	cin >> m1;
	cin >> y1;
	cout << "You want to enter weeks or days w for Weeks d for days:";
	cin >> input;
	if (input == 'w')
	{
		cout <<endl<< "Enter weeks you want to add:";
		cin >> weeks;
		days = weeks * 7;
		c2.futuredate(d1, m1, y1, days);
	}
	 else if (input == 'd')
	{
		cout <<endl<< "Enter days you want to add: ";
		cin >> days;
		c2.futuredate(d1, m1, y1, days);
	}

	cout << "................Enter starting Date and Month and year 3.1.2032//3.1.2032..........:" << endl;
	cin >> d1;
	cin >> m1;
	cin >> y1;
	cout << "You want to enter weeks or days w for Weeks d for days e.g 20//80:";
	cin >> input;
	if (input == 'w')
	{
		cout <<endl<< "Enter weeks you want to subtract from:";
		cin >> weeks;
		days = weeks * 7;
		c2.futuredates(d1, m1, y1, days);
	}
	else if (input == 'd')
	{
		cout <<endl<< "Enter days you want to subtract from:";
		cin >> days;
		c2.futuredates(d1, m1, y1, days);
	}
	return 0;
}