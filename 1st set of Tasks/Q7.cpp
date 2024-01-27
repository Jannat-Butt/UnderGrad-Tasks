#include<iostream>
using namespace std;

void AsterisksToBePrinted(int iAster);//prototype
void SpacesToBeGiven(int iSpace);//prototype
void ZisDisplayed(int ilength, int count_rows);//prototype

int main()
{
	int ilength = 0;
	cout << "Enter The Length of top line:";
	cin >> ilength;
	ZisDisplayed(ilength, 0);
	return 0;
}


//Function that prints whole (Z) and taking two parameters
//ilength is the input also used as base case(to stop execution)
//count_rows is for if condition which will print * for first and last line

void ZisDisplayed(int ilength, int count_rows)
{
	//temp variable to hold origional value of ilength from main()
	//which will not change after first execution

	static int temp = ilength;
	if (ilength == 0)//base case
	{
		return;
	}
	else
	{
		//if cond for first and last line of pattern

		if (count_rows == 0 || count_rows == temp - 1) //temp-1 is showing the origional value of
													   //ilength(temp) is decremented by one for
		{                                              //the execution of last line
			AsterisksToBePrinted(temp);
			cout << endl;
			ZisDisplayed(ilength - 1, count_rows + 1);
		}
		else
		{
			//when line is not the first or last these functions will be called for the middle structure of Z

			SpacesToBeGiven(ilength - 1);
			AsterisksToBePrinted(1);
			cout << endl;

			//Here function is called and ilength is decremented moving close to stopping criteria
			//count of rows is incrementing which will help to execute upper if to print last line

			ZisDisplayed(ilength - 1, count_rows + 1);
		}

	}
}

void SpacesToBeGiven(int iSpace)
{
	if (iSpace == 0)//base case
	{
		return;
	}
	else
	{
		cout << " " << " ";
		SpacesToBeGiven(iSpace - 1);

	}
}

void AsterisksToBePrinted(int iAster)
{
	if (iAster == 0) //base case
	{
		return;
	}
	else
	{
		cout << "*" << " ";
		AsterisksToBePrinted(iAster - 1);
	}
}
