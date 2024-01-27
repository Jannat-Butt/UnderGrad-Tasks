#include<iostream>
using namespace std;

class String
{
private:
	char* string;
	int s;
public:

	String();
	String(char* str, int);
	String(const String&);
	char getAt(int i);
	void setAt(int, char);
	void append(char a);
	void append(String str);
	int length();
	void display()const;
	bool isEmpty();
	void copy(const char*);
	int find(char);
	bool equal(String);
	void append(const char*);
	String(int x);
	void copy(const String&);
	String substr(int pos);
	char* tocstring();
	String substr(int pos, int);
	int stoi();
	//~String();
};
String::String()
{
	string = NULL;
}

//initializing the char array with user input
String::String(char* str, int s)
{
	this->s = s;
	string = new char[s];
	for (int i = 0; i < s; i++)
	{
		string[i] = str[i];
	}
}
//displaying the string
void String::display()const
{
	for (int i = 0; i < s; i++)
	{
		cout << string[i];
	}
}
//returning the char at specific index i
char String::getAt(int i)
{
	return (this->string[i]);
}
//takes index from user and than asks
//to set a character than 
//sets that char at that index
void String::setAt(int i, char c)
{
	this->string[i] = c;
}
//appending user entered character at the end of string
void String::append(char a)
{
	int count = 1;
	int size = this->s + 1;
	//making new array of previous string plus one more index
	//to store char a
	char* newstring = new char[size];
	for (int i = 0; i < size; i++)
	{
		if (count == size)
		{
			newstring[i] = a;
		}
		else
		{
			newstring[i] = this->string[i];
			count++;
		}
	}
	//displaying the string apeended one
	cout << "Your new appended String is:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << newstring[i];
	}
	cout << endl;
	delete[]newstring;
}
//returns the length/size that is in use
int String::length()
{
	return this->s;
}
//checks if the caller obj string is null or not
//check for an empty of non empty string
bool String::isEmpty()
{
	if (*(this->string) == '\0')
	{
		return true;
	}
	return false;
}
//copying a const char array in new char array
void String::copy(const char* s)
{
	int size = 0;
	while (*s != '\0')
	{
		size++;
		s++;
	}
	s = s - size;
	//making new array of size that we have find 
	//of const char
	string = new char[size];
	for (int i = 0; i < size; i++)
	{
		string[i] = s[i];
	}
	cout << "I have copied you string and after copying:" << endl;
	//displaying string
	for (int i = 0; i < size; i++)
	{
		cout << string[i];
	}
	cout << endl;
}
//this will find the char that user entered
int String::find(char search)
{
	int find = 0;
	//count will count that how many times this char is found
	int count = 0;
	for (int i = 0; i < this->s; i++)
	{
		if (this->string[i] == search)
		{
			find = i;
			count++;
		}
	}

	cout << "I found " << search << " " << count << " " << "times:";
	return find;
}
//this will append an obj str at the end of caller obj
void String::append(String str)
{
	int counter = 0, i;
	int size = this->s + str.s;
	//dynamically allocating
	char* newstring = new char[size];
	for (i = 0; i < this->s; i++)
	{
		//caller obj string is first copied as it is
		newstring[i] = this->string[i];
		counter++;
	}
	//rest of the indexes will be filled with the parametre  str
	for (i = 0; i < str.s; i++)
	{
		newstring[counter] = str.string[i];
		counter++;
	}
	//displaying string
	cout << "Your appended string turns out to be:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << newstring[i];
	}
	cout << endl;
	delete[]newstring;
}
//checks if both strings are equal
bool String::equal(String strr)
{
	int count = 0;
	for (int i = 0; i < this->s || i < strr.s; i++)
	{
		//once that index of caller obj != the value at index of strr string
		//it will make count=1
		//and loop will break
		if (this->string[i] != strr.string[i])
		{
			count = count + 1;
			break;
		}
	}
	//if count is 1 means strings was not equal
	//if this is 0 means equal
	return(count == 0);
}
//appending const char 
void String::append(const char* str)
{
	int size = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		size++;
		i++;
	}
	int counter = 0, index;
	int sofarray = this->s + size;
	char* string = new char[sofarray];
	//making new array of size for appended string
	for (index = 0; index < this->s; index++)
	{
		string[index] = this->string[index];
		counter++;
	}
	for (index = 0; index < size; index++)
	{
		string[counter] = str[index];
		counter++;
	}
	//displaying string
	cout << "...Your APPENDED STRING.....:";
	for (index = 0; index < sofarray; index++)
	{
		cout << string[index];
	}
	delete[]string;
}
//copying the parametre string to caller obj string
String::String(const String& str)
{
	this->s = str.s;
	string = new char[this->s];
	for (int i = 0; i < this->s; i++)
	{
		//copying index by index 
		this->string[i] = str.string[i];
	}
}
//initializing the string with user defined size
String::String(int x)
{
	this->s = x;
	string = new char[x];
	for (int i = 0; i < x; i++)
	{
		//also initializing all indexes with F
		this->string[i] = 'F';
	}
}
//copying the string which is passed as parametre to
//dynamilcally allocated array of same size
void String::copy(const String& str)
{
	char* strr = new char[str.s];
	for (int i = 0; i < str.s; i++)
	{
		strr[i] = str.string[i];
	}
	cout << "..............I am copying String 1 to String 2............" << endl;
	//displaying string
	for (int i = 0; i < str.s; i++)
	{
		cout << strr[i];
	}
	delete[]strr;
}
//finding substring
String String::substr(int pos)
{
	int size = this->s - pos;
	//size will containg size of caller obj - pos(from which substr will strt)
	String temporary(size);
	//this is the obj of String class having size we have find
	for (int i = 0; i < size; i++)
	{
		temporary.string[i] = this->string[pos];
		//pos++ will move the origional string forward
		pos++;
	}
	return temporary;
	//returning the temp string to main
}
//convertig str to cstring
char* String::tocstring()
{
	//making dynamic char array
	char* temp = new char[this->s];
	//moving the caller obj string index by index to the tem char array
	for (int i = 0; i < this->s; i++)
	{
		temp[i] = this->string[i];
	}
	return temp;
	//de-allocate
	delete[]temp;
}
//finding substring
String String::substr(int pos, int len)
{
	int s = len - pos;
	//s is size like we want from index 2 to 4 therefore,
	//s=4-2=2
	String temp(s);
	//temp i obj of String it will make a string of size s
	for (int i = 0; i < s; i++)
	{
		temp.string[i] = this->string[pos];
		//pos will move string to forward direction
		pos++;
	}
	return temp;
}
//string to integer function
int String::stoi()
{
	int counting = 0;
	//as 0-9 are represented as 48-57
	//so I am setting start to be 48
	int start = 48;
	for (int i = 0; i < this->s; i++)
	{
		//if caller obj string at specific index goes out of range
		//greater than 48 less than 57 than it cannot convert that string
		if (this->string[i] < 48 || this->string[i] >57)
		{
			cout << "Cannot convert your string to int:" << endl;
		}
		else
		{
			//formula for calculation
			//start has value 48 from where 0 value starts
			counting = (counting * (10) + (this->string[i] - start));
			// suppose 051 is string
			//0 has value of 48
			//above execution will be 0*10=0 + 48-48=0
		}
	}
	return counting;
}
/*
String::~String()
{
	delete[]string;
}
*/