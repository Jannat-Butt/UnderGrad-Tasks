using namespace std;
//..................................................QUESTION 2....................................................//
struct Car
{
private:
	int petrolLevel;
public:
	//default constructor
	Car() {
		petrolLevel = 0;
	}
	//this cons is exception petrol value
	//and assigning it to petrol
	Car(int petrolLevelVal)
	{
		//this checks if petrol lvl is less than or =to 45
		if (petrolLevelVal <= 45)
		{
			//it will refill it
			petrolLevel = petrolLevelVal;
		}
		//else assign 0
		petrolLevelVal = 0;
		petrolLevel = petrolLevelVal;
	}
	//setter for setting petrol
	void setPetrolLevel(int petrolLevelVal)
	{
		if (petrolLevelVal <= 45)
		{
			//checks it is below or equal 45 or not
			petrolLevel = petrolLevelVal;
		}
	}
	//getter
	int getPetrolLevel()const
	{
		//this will return petrol level
		return petrolLevel;
	}
	//return 1 if car moves 
	//0 if it doesnot moves
	bool MoveCar(int distanceKM)
	{
		if (petrolLevel <= 0)
		{
			//if initially petrol is 0 than car will not move
			return false;
		}
		else
		{
			//it will continue loop till distance entered
			//and for each km it will decrement petrollevel
			for (int i = 0; i < distanceKM; i++)
			{
				petrolLevel--;
			}
		}
		//finally returns 1
		return true;
	}
	//function for refilling
	void Refill()
	{
		if (petrolLevel == 0)
		{
			//if 0 petrol it will fill the tank
			petrolLevel = 45;
		}
	}
	//check if tank is empty
	bool isEmpty()
	{
		//if petrol is 0 than tank is empty
		if (petrolLevel <= 0)
			return 1;
		else
			return 0;
	}
};

