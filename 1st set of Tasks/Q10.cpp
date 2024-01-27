
#include <iostream>
using namespace std;

void diagonal(int n);
void displayOne(int n);
void nCombinations(int n, int count);

int main()
{
    int n;
    cout << "Enter Number(rows):";
    cin >> n;
    nCombinations(n, 1);
    return 0;
}
//This function will dispay 1 in each row except the last row
void displayOne(int nRows)
{
    if (nRows == 0)
    {
        return;
    }
    else
    {
        //at first execution (n-1) Rows-1 is recieved as(parametre) and 
        //aftrer that in each next execution rows will be decremented 2 times
        //and will be passed as argument to this function
        displayOne(nRows - 1);
        cout << "1"<<" ";
    } 

}
//This function will print the diagonal entries
//diagonal entries number starts from 1 and goes till number of rows(n)
void diagonal(int dig_entries)
{
    if (dig_entries == 0)
    {
        return;
    }
    else
    {
        cout << dig_entries;
        diagonal(dig_entries - dig_entries);//this statement ensures that this function 
    }                                       //only executes for 1 time in each call
}

//This function will call other two functions
//and displays the whole pattern
void nCombinations(int nRows, int count)
{
    //base case
    if (nRows == 0)
    {
        return;
    }
    else
    {
        //display0ne function is called 
        displayOne(nRows - 1);
        //diagonal function will be called
        diagonal(count);
        //moving on next line
        cout << endl;
        //rows will be decremented on each call
        //and count will be incremented on each call
        nCombinations(nRows - 1, count + 1);
    }
}

