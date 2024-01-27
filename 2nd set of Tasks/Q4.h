using namespace std;
//..................................................Question 4.....................................................//
struct Address
{
	char* address;
	char* city;
	char* state;
	int zip_code;
	Address()
	{
		this->address = NULL;
	}
};
struct CustomerAccount
{
	char* name;
	Address address;
	long long phoneNum;
	float balance;
	char* accountNum;
};
void OpenCustomerAccount(CustomerAccount* customers[], int&
	accountsOpen, char* NameVal, char* addVal, char* cityVal, char* stateVal, int
	zipcodeVal, long long phoneVal, float balanceVal)
{
	CustomerAccount* newcustmr = new CustomerAccount[accountsOpen];
	for (int i = 0; i < accountsOpen; i++)
	{
		
		newcustmr[i].name = NameVal;
		newcustmr[i].balance = balanceVal;
		newcustmr[i].phoneNum = phoneVal;
		newcustmr[i].address.address = addVal;
		newcustmr[i].address.city = cityVal;
		newcustmr[i].address.state = stateVal;
		newcustmr[i].address.zip_code = zipcodeVal;
	}
}

/*int SearchCustomer(CustomerAccount* customers[], int accountsOpen, char*
	accountNum)
{
	char
	for (int i = 0; i < accountsOpen; i++)
	{
		if (customers[i] == accountNum)
		{
			return i;
		}
		//customers++;
	}
	return 0;
}*/
/*bool UpdateCustomerAccount (CustomerAccount* customers[], int accountsOpen,
char*accountNumVal, Address addressVal)
{
}*/