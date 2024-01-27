#include<iostream>
using namespace std;

void getName(char* namePtr, int sizeOfarray)
{
    if (sizeOfarray == 0)
    {
        return;
    }
    else
    {
        //*namePtr will take letter and than function is called
        cin >> *namePtr;
        //function is called and pointer will move to next location
        getName(namePtr + 1, sizeOfarray - 1);
        //at the last execution pointer will be at last location and have all the letters(as an array of characters)
    }
}
void reverse_string(char* namePtr, int sizeOfarray)
{
    if (sizeOfarray == 0)//base case
    {
        return;
    }
    else
    {
        //recursively function will be called and 
        //pointer will move from starting location to last memory address
        reverse_string(namePtr + 1, sizeOfarray - 1);
        //when function is returned the last value (character)that pointer points to is displayed 
        //this will again return to previous loaction,so on and so forth array of chars will be 
        //displayed in reverse order.
        cout << *namePtr;
    }
}

int main()
{
    //size for the array
    int size;
    cout << "Enter the size of your name e.g(jannat)(6):";
    cin >> size;
    //dynamic array 
    char* string = new char[size];
    if (size == 0)
    {
        cout << "You do not entered a proper size ";
    }
    else
    {
        cout << "Enter string and press enter:";
        //recursive function call to input the name
        getName(string, size);
        cout << " " << "Reverse String:";
        //recursive function to reverse string
        reverse_string(string, size);
    }
    delete[]string;
    string = NULL;
    return 0;
}
