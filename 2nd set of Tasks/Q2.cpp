#include<iostream>
#include"Q2.h"
using namespace std;
int main()
{
	//.....................................................Question 2.............................................//

	Car c1;
	int petrol, distance;
	cout << "Enter petrol level:";
	cin >> petrol;
	cout << "Enter distance to cover:";
	cin >> distance;
	Car c2(petrol);
	c2.setPetrolLevel(petrol);
	cout << "Petrol Level=" << c2.getPetrolLevel() << endl;
	if (c2.isEmpty())
	{
		cout << "...................Petrol tank is empty..........." << endl;
	}
	else
	{
		cout << "..................Petrol tank is full..............." << endl;
	}
	if (c2.isEmpty())
	{
		cout << "............Tank is now refilled automatiaclly.....:" << endl;
		c2.Refill();
	}
	if (c2.MoveCar(distance))
	{
		cout << "............WOOHO!!Car is successfully moved!!............." << endl;
	}
	else
	{
		cout << "...................!!Car is not moved!! .................." << endl;
	}

	return 0;
}

	//................................................END...................................//