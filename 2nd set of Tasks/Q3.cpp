#include<iostream>
#include"Q3.h"
using namespace std;
int main()
{
	int size, index, pos, len;
	char c;
	cout << "Enter size of string=";
	cin >> size;
	char* str = new char[size];
	for (int i = 0; i < size; i++)
	{
		cin >> str[i];
	}
	String str1(str, size);
	cout << "Your string is:" << endl;
	str1.display();
	cout << endl << endl;
	delete[]str;

	cout << "From your Name enter index Which you want:";
	cin >> index;
	cout << endl << "Your character at" << " " << index << " " << "index" << "is:" << endl << str1.getAt(index) << endl << endl;

	cout << "Enter Index where you want to insert new Character:";
	cin >> index;
	cout << endl << "Which character you want to insert:";
	cin >> c;
	str1.setAt(index, c);
	cout << endl << "Your New string is:" << endl;
	str1.display();
	cout << endl;

	cout << "Which character you want to insert at last :";
	cin >> c;
	cout << endl;
	str1.append(c);

	cout << endl;

	cout << "Enter size of string you want to apend:";
	cin >> size;
	cout << endl;
	char* strr = new char[size];
	for (int i = 0; i < size; i++)
	{
		cin >> strr[i];
	}
	String str2(strr, size);
	cout << "YOU ENTERED:" << endl;
	str2.display();
	cout << endl;
	str1.append(str2);
	delete[]strr;

	cout << endl << "Length of String 1:" << str1.length() << endl;

	if (str1.isEmpty())
	{
		cout << "String is Empty:" << endl;
	}
	else
		cout << "String is Not Empty:" << endl;

	char string[7] = { 'J','A','N','N','A','T' };
	String temp;
	temp.copy(string);

	cout << "From your name which character you want to find:";
	cin >> c;
	cout << endl << "Also I found" << " " << c << " " << "at " << str1.find(c) << " " << "index:" << endl;

	cout << "Enter size of string you want to check if same or not:";
	cin >> size;
	cout << endl;
	char* strtcompare = new char[size];
	cout << "Enter your string:" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> strtcompare[i];
	}
	String str3(strtcompare, size);
	cout << "Your string is:" << endl;
	str3.display();
	cout << endl;
	cout << "From string which it was compared is:" << endl;
	str1.display();
	cout << endl;
	cout << "I am comparing Your strings:" << str1.equal(str3) << endl << endl;
	delete[]strtcompare;

	char appendString[5] = { 'F','A','S','T' };
	cout << "First string is:" << endl;
	str3.display();
	cout << endl;
	cout << "String to be appended is:" << endl;
	cout << appendString;
	cout << endl;
	str3.append(appendString);

	String copiedStr = str1;
	cout << endl << "STRING 1 IS:" << endl;
	str1.display();
	cout << endl << "................Copy Constructor is calling..............:" << endl;
	cout << endl;
	copiedStr.display();
	cout << endl;

	String predefined(3);
	cout << ".......I have initialized the array of pre defined size.....:" << endl << endl;
	cout << "And the string is:" << endl;
	predefined.display();
	cout << endl << endl;

	cout << endl << "STRING 1 IS:" << endl;
	str1.display();
	cout << endl << "STRING 2 IS:" << endl;
	str2.display();
	cout << endl;
	str2.copy(str1);

	String substrPos;
	cout << endl << "You will recieve substring of string 1 which is:" << endl;
	str1.display();
	cout << endl << ".................Enter the index from where you want string........:" << endl;
	cin >> index;
	cout << endl << endl;
	cout << ".............Substring is.........." << endl;
	substrPos = str1.substr(index);
	substrPos.display();
	cout << endl << endl;

	cout << "String is:" << endl;
	str1.display();
	cout << endl << "I am converting String to cstring:" << endl;
	char* result = str1.tocstring();
	for (int i = 0; i < str1.length(); i++)
	{
		cout << result[i];
	}

	cout << endl << ".........This is the string........... " << endl;
	str1.display();
	cout << endl << "Enter pos and than length" << endl;
	cin >> pos >> len;
	String sub;
	sub = str1.substr(pos, len);
	cout << "Now your Substring is:" << endl;
	sub.display();
	cout << endl;

	cout << "..................Enter size of string that you want to convert to stoi.........." << endl;
	cin >> size;
	cout << endl << "...............Enter String that should be Integers...........:" << endl;
	char* stointeger = new char[size];
	for (int i = 0; i < size; i++)
	{
		cin >> stointeger[i];
	}
	String stoint(stointeger, size);
	int intvalue;
	intvalue = stoint.stoi();
	cout << "............I have converted your sting to integer:" << intvalue;
	return 0;
}