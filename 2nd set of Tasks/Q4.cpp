#include<iostream>
#include"Q4.h"
using namespace std;
//...............................................Question 4..............................................//
int main()
{
	int accountsopen, sname, scity, sstate;
	int zipc;
	char* city = NULL;
	char* state = NULL;
	long long phonenum;
	float balance;
	cout << "How many customers are there:";
	cin >> accountsopen;
	cout << "Enter size of your name:";
	cin >> sname;
	char* name = new char[sname];
	char* address = new char[25];
	CustomerAccount* customers = new CustomerAccount[accountsopen];
	for (int i = 0; i < accountsopen; i++)
	{
		cout << "Enter your name:";
		for (int i = 0; i < sname; i++)
		{
			cin >> name[i];
		}
		cout << "Enter your address:" << endl;
		cout << "Enter E to exit" << endl;
		for (int i = 0; i < 25; i++)
		{
			cin >> address[i];
			if (address[i] == 'E')
			{
				break;
			}
		}
		cout << "Enter size of your city name:";
		cin >> scity;
		 city = new char[scity];
		cout << "Enter your city name:";
		for (int i = 0; i < scity; i++)
		{
			cin >> city[i];
		}
		cout << "Enter size of your state name:";
		cin >> sstate;
		 state = new char[sstate];
		cout << "Enter your state name:";
		for (int i = 0; i < sstate; i++)
		{
			cin >> state[i];
		}
		cout << "Enter your zipcode:";
		cin >> zipc;
		cout << "Enter your phone number:";
		cin >> phonenum;
		cout << "Enter your balance:";
		cin >> balance;
	}
	//char acc[6] = { 'P','k',0,0,1 };
	OpenCustomerAccount(&customers, accountsopen, name, address, city, state, zipc, phonenum, balance);
	//SearchCustomer(&customers, accountsopen, acc);
	delete[]address;
	delete[]name;
	delete[]city;
	delete[]state;
	return 0;
}

//............................................END.................................................//

