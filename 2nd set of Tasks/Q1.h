
using namespace std;
//..................................................QUESTION 1..............................................//
struct Rectangle {
private:

	int w;// width
	int h; // height
	int area;
	int x;
	int y;
public:
	int a;
	int b;
	int c;
	Rectangle(int height, int width, int xcoor, int ycoor)
	{
		w = width;
		h = height;
		x = xcoor;
		y = ycoor;
	}
	void Display(Rectangle rect)
	{
		cout << "Line is:";
		cout << this->a << "*" << rect.x << "+" << this->b << "*" << rect.y << "+" << this->c;
	}
	Rectangle() {}
	int calarea()
	{
		//area of calling object is equal to width * height
		this->area = w * h;
		return area;
	}
	//let us understand this from simple a,b,c variables
	void sortarea(Rectangle r2, Rectangle r3)
	{
		//it is based on as a<=b && a<=c
		if (this->area <= r2.area && this->area <= r3.area)
		{
			//as b<=c
			if (r2.area <= r3.area)
			{
				cout << "SORTED RECTANGLE" << endl;
				cout << this->area << endl << r2.area << endl << r3.area << endl;
			}
			// if b i not <=c than c<=b
			else
			{
				cout << "SORTED RECTANGLE" << endl;
				cout << this->area << endl << r3.area << endl << r2.area << endl;
			}
		}
		//this is considered as if b<=a && b<=c
		else if (r2.area <= this->area && r2.area <= r3.area)
		{
			//as if a<=c
			if (this->area <= r3.area)
			{
				cout << "SORTED RECTANGLE" << endl;
				cout << r2.area << endl << this->area << endl << r3.area << endl;
			}
			//else if a is not <=c than c<=a
			else
			{
				cout << "SORTED RECTANGLE" << endl;
				cout << r2.area << endl << r3.area << endl << this->area << endl;
			}
		}
		//can be considered as c<=a  && c<=b
		else if (r3.area <= this->area && r3.area <= r2.area)
		{
			//if a<=b
			if (this->area <= r2.area)
			{
				cout << "SORTED RECTANGLE" << endl;
				cout << r3.area << endl << this->area << endl << r2.area << endl;
			}
			//else if a is not <=b than b<=a
			else
			{
				cout << "SORTED RECTANGLE" << endl;
				cout << r3.area << endl << r2.area << endl << this->area << endl;
			}
		}

	}
	//it will compare if caller objs area is greater than the parametre one
	bool compareRectangle(Rectangle r2)
	{
		return (this->area > r2.area);
	}
	//this func will check that the caller obj plus rect r2 and rect r3 
	//which is same
	void sameArea(Rectangle r2, Rectangle r3)
	{

		if (this->area == r2.area)
		{
			//caller obj area is equal to r2
			cout << "R1 area is equal to R2 area:" << endl;
			cout << "Where area of R1 is" << " " << this->area << endl;
			cout << "and area of R2 is" << " " << r2.area << endl;
			cout << endl;
		}
		if (this->area == r3.area)
		{
			//caler obj area is equal to r3
			cout << "R1 area is equal to R3 area:" << endl;
			cout << "Where area of R1 is" << " " << this->area << endl;
			cout << "and area of R3 is" << " " << r3.area << endl;
			cout << endl;
		}
		if (r2.area == r3.area)
		{
			//r2 area is equal to r3 area 
			cout << "R2 area is equal to R3 area:" << endl;
			cout << "Where area of R2 is" << " " << r2.area << endl;
			cout << "and area of R3 is" << " " << r3.area << endl;
			cout << endl;
		}

	}
	//cheching for intersection of lines
	bool rectangleintersection(Rectangle l1)
	{
		//this is the formula 
		int intersection = 0;
		if (l1.a * this->x + l1.b * this->y + l1.c < 0)
		{
			intersection = intersection + 1;
		}
		if (l1.a * this->x + l1.b * (this->y + this->h) + l1.c < 0)
		{
			intersection = intersection + 1;
		}
		if (l1.a * (this->x + this->w) + l1.b * this->y + l1.c < 0)
		{
			intersection = intersection + 1;
		}
		if (l1.a * (this->x + this->w) + l1.b * (this->y + this->h) + l1.c < 0)
		{
			intersection = intersection + 1;
		}
		//if intersection value is between 1-3 it will return true
		return (intersection != 0 && intersection != 4);
	}
};
