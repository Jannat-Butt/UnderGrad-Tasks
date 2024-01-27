using namespace std;
class Calender
{
private:
	int year;
	int month;
	//Manually made a pointer to char array 
	//array of months
	const char*monthsInYear[13]={ "January","February","March","April","May",
						 "June","July","Aug","Sept","October","November","Decemeber" };
	//Array for storing days of each month
	int daysInMonth[13]= { 31,28,31,30,31,30,31,31,30,31,30,31 };
	//array if a year is leap it will combiendays of every month jan(31) feb(29) 31+29=60 and so on
	int combinedLeapDays[12] = { 31,60,91,121,152,182,213,244,274,305,335,366 };
	//array it will combiendays of every month e.g jan(31) feb(28) 31+28=59 so on and so forth
	int combinedDays[12] = { 31,59,90,120,151,181,212,243,273,304,334,365 };
public:
	Calender();
	void DisplayCalender(int,int);
	void checkLeapYear(int,int);
	void differenceofDates(int, int, int,int,int,int);
	int checkLeapYear(int year);
	void futuredate(int, int, int, int);
	void futuredates(int, int, int,int);

};
Calender::Calender()
{	
}
	
void Calender::checkLeapYear(int year,int month)
{
	//caller obj year will have year 
	this->year = year;

	//caller obj month will have month
	this->month=month;
	if (((this->year % 4 == 0) && (this->year % 100 != 0)) || (this->year % 400 == 0))
	{
		cout << "................ ...This is Leap Year.............." << endl;
		//the caller obj will store 29 on daysinmonth[1] means in feb will have 29 days
		this->daysInMonth[1] = 29;
	}
	
}
void Calender::DisplayCalender(int year,int month)
{
	//alignment will control the display of dates
	int alignment = 1;
	//function call for checking leap year
	checkLeapYear(year,month);
	int daysInSpecificMonth = this->daysInMonth[this->month];

	cout << "........................." << monthsInYear[month-1] << "......................."<<endl;
	cout << "Sunday" << " " << " " << "Monday" << " " << " " << "Tuesday" << " " << " " << "Wed" << " " << " "
		<< "Thursday" << " " << " " << "Friday" << " " << " " << "Saturday"<<endl;
	//daysinspecific month will store the days which user have entered [month]==days in that month
	for (int i = 1; i <= daysInSpecificMonth; i++)
	{
		//i will display the dates from 1 to the specific Date for each Month
		cout <<" " << i << "\t"<<" ";
		//alignment will control the display of dates 
		//7 becaise from mon-sun
		if (alignment == 7)
		{
			cout << endl;
			alignment = 1;
		}
		else
		{
			alignment++;
		}
	} 
	cout << endl;
}
//this is second check for leap year because in this im returning true or false
int Calender::checkLeapYear(int year)
{
	this->year = year;
	int count = 0;
	if (((this->year % 4 == 0) && (this->year % 100 != 0)) || (this->year % 400 == 0))
	{
		count++;
	}
	//if count will be one means leap
	//otherwise false
	return (count == 1);
}
void Calender::differenceofDates(int d1, int m1, int y1,int d2,int m2,int y2)
{
	//firstdays will store 1/1/0000 to d1 m1 and y1 date
	int firstdays=0;
	//difder will store days upto m1 d1 y1 and m2 y2 d2
	int differ = 0;
	int total = 365;
	firstdays = firstdays+y1 * total;
	//if year is leap it will add days of leapyear of specific month
	if (checkLeapYear(y1) == 1)
	{
		firstdays = firstdays + combinedLeapDays[m1];
	}
	else
	{
		firstdays = firstdays + combinedDays[m1];
	}
	firstdays = firstdays + d1;
	int seconddays = 0;
	//secondays will store 1/1/0000 to d2 m2 and y2 date
	seconddays = seconddays + y2 * total;
	if (checkLeapYear(y2) == 1)//function call
	{
		seconddays = seconddays + combinedLeapDays[m2];
	}
	//if year is not leap it will add days of normal year of specific month
	else
	{
		seconddays = seconddays + combinedDays[m2];
	}
	seconddays = seconddays + d2;
	//to make sure smaller value is being subtracted from larger
	if (seconddays > firstdays)
	{
		differ = seconddays - firstdays;
	}
	else
	{
		differ = firstdays - seconddays;
	}
	int weeks = 0;
	int days = 0;
	//calculating weeks
	weeks = differ / 7;
	//calculating remaining days that are not included in weeks
	days = differ % 7;
	cout << "................Difference between two dates is..........:" << differ<<endl;
	cout <<endl<<".......................Number of weeks::" << weeks << endl;
	cout <<endl<< "........................Number of days:" << days<< endl;
}

//calculating future  date
void Calender::futuredate(int date, int month, int yr,int add)
{
	//feb is storing 29 in case for leap year
	//total month 12 in one year
	int febmonth = 29, totalMonths = 12;
	bool yearisLeap = 0;
	//assigning year to the year of caller obj
	this->year = yr;
	this->month = month;
	//now i am adding the starting date to the date(day) that user wants to increment
	date = date + add;
	//i will now check if year is leap or not
	yearisLeap = checkLeapYear(year);

	//loop will continue if the date after increment
	//is greater than the days in that specific month
	for (int i = 0;(date> daysInMonth[this->month - 1]); i++)
	{
		//if leap year and month is also second(feb)
		 if (this->month==2 && yearisLeap==true )
		{
			//date will subtract the feb (days)
			//as year is also leap so 29 days will be subtracted
			date = date - febmonth;
			//afterwords new month will start
			this->month = this->month + 1;
		}
		else
		{
			//in case year is not leap date will be subtracted from normal 
			//year calender e.g days[3-1]  so days[2] and days in 2nd month 31 
			date = date - daysInMonth[this->month - 1];
			//afterwords new month will start
			this->month = this->month + 1;
		}
		 //if the given month is greater than 12 months
		//than month will become 1
		//this means new month is started of new year
		 if (this->month > totalMonths)
		 {
			 //new year begins
			 this->year = this->year + 1;
			 //it will again check if year is leap or not
			 yearisLeap = checkLeapYear(year);
			 //month is now january
			 this->month = 1;
		 }
		//this loop will execute till condition is not false
	}
	//Here it will displat Future date in format 2 June 2001
	cout << endl << "...........Future Date.........." << endl;
	cout<<date << " " << " " << monthsInYear[this->month-1] << " " << this->year << endl;
}



//calculating past date
void Calender::futuredates(int date, int month, int yr, int sub)
{
	//feb is storing 29 in case for leap year
	//total month 12 in one year
	int febmonth = 29, totalMonths = 12;
	//assigning year to the year of caller obj
	bool yearisLeap = 0;
	this->year = yr;
	this->month = month;
	//to make sure smaller is subtracted from bigger

	if (sub > date)
	{
		date = sub - date;
	}
	else
	{
		date = date - sub;
	}
	//i will now check if year is leap or not
	yearisLeap = checkLeapYear(year);

	//condition will continue if the date after decrement
	//is smaller than the days in that specific month
	if (date < daysInMonth[this->month - 1])
	{
		//if leap year and month is also second(feb)
		if (this->month == 2 && yearisLeap == true)
		{
			//date will subtract the feb (days)
			//as year is also leap so date is subtracted from feb(29)
			date = febmonth - date;
			//afterwords month will move 1 month back
			this->month = this->month - 1;
		}
		else
		{
			//in case year is not leap it will check
			//and date will be subtracted from total number of days
			//of specific month
			date = daysInMonth[this->month - 1] - date;
			//if month is 0 than it will make it 12 means (December)
			this->month = (this->month - 1);
			if (this->month == 0)
			{
				this->month = 12;
			}
		}
		//if month is greater of equal to 12 than year will be decremented
		if (this->month >= totalMonths)
		{
			this->year = this->year - 1;
		}
		//Here it will displat past date in format 2 June 2001
		cout << endl << "...........Past Date.........." << endl << date << " " << " " << monthsInYear[this->month - 1] << " " << this->year << endl;
	}

	else if ((date > daysInMonth[this->month - 1]))
	{

		//condition will continue if the date after decrement
	 //is larger than the days in that specific month
		for (int i = 0; (date > daysInMonth[this->month - 1]); i++)
		{
			//if leap year and month is also second(feb)
			if (this->month == 2 && yearisLeap == true)
			{
				//date will subtract from the feb (days)
				//as year is also leap so date is subtracted from feb(29)
				date = date-febmonth ;
				//afterwords month will move 1 month back
				this->month = this->month - 1;
			}
			else
			{
				//in case year is not leap it will check
				//and than days of specific month will be subtracted from date
				date = date-daysInMonth[this->month - 1];
				//month is decremented to previous
				this->month = (this->month - 1);
				//if month is 0 than it will make it 12 means (December)
				if (this->month == 0)
				{
					this->month = 12;
				}
			}
			if (this->month >= totalMonths)
			{
				//year is decremented to one 
				this->year = this->year - 1;
				//it will again check if year is leap or not
				yearisLeap = checkLeapYear(year);
			}
			//loop will continue untill statement is false
		}
		//Here it will display past date in format 2 June 2001
		cout << endl << "...........Past Date.........." << endl << date << " " << " " << monthsInYear[this->month-2] << " " << this->year << endl;
	}
}
