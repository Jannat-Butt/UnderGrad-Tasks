#include<iostream>
#include"Q1.h"
using namespace std;
//.....................................Question 1...................................//
int main()
{
int height[3], width[3], x[3], y[3];
for (int i = 0; i < 3; i++)
{
	cout << "Enter height of" << " " << i + 1 << " " << "Rectangle:";
	cin >> height[i];
	cout << "Enter width of" << " " << i + 1 << " " << "Rectangle:";
	cin >> width[i];
	cout << "Enter xcoordinate of" << " " << i + 1 << " " << "Rectangle:";
	cin >> x[i];
	cout << "Enter ycoordinate of" << " " << i + 1 << " " << "Rectangle:";
	cin >> y[i];

}
Rectangle r1(height[0], width[0], x[0], y[0]);
Rectangle r2(height[1], width[1], x[1], y[1]);
Rectangle r3(height[2], width[2], x[2], y[2]);

cout << endl;
cout << "Area of Rectangle 1:" << r1.calarea() << endl;
cout << "Area of Rectangle 2:" << r2.calarea() << endl;
cout << "Area of Rectangle 3:" << r3.calarea() << endl;
cout << endl;
r1.sortarea(r2, r3);
cout << endl;
cout << "Comaring R1 and R2" << endl;
cout << r1.compareRectangle(r2) << endl;
cout << endl;
r1.sameArea(r2, r3);

// random line is the obj of rectangle
Rectangle randomLine;
//public members of rectangle is being initialized
randomLine.a = rand() % 10 - 3;
randomLine.b = rand() % 10 - 3;
randomLine.c = rand() % 10 - 3;
//displaying random lines for all 3 rectangles
randomLine.Display(r1);
cout << endl;
randomLine.Display(r2);
cout << endl;
randomLine.Display(r3);

//these intersect variables are storing 0 or 1
//if any of these will have 1 it means that that rectangle has intersected
//if any of these will have 0 it means that that rectangle is not intersected
int intersect1 = 0, intersect2 = 0, intersect3 = 0;
intersect1 = r1.rectangleintersection(randomLine);
intersect2 = r2.rectangleintersection(randomLine);
intersect3 = r3.rectangleintersection(randomLine);

//this will basically see if intersects have 0 or 1
//1 means intersected
//0 means not intersected
if (intersect1 != 0)
{
	cout << endl << "Rectangle 1 intersects" << endl;
}
else
cout << "Rectangle 1 doesnot intersects" << endl;
if (intersect2 != 0)
{
	cout << "Rectangle 2 intersects"<<endl;
}
else
cout << "Rectangle 2 doesnot intersects" << endl;

if (intersect3 != 0)
{
	cout << "Rectangle 3 intersects" << endl;
}
else
cout << "Rectangle 3 doesnot intersects" << endl;

//this will show from 3 rectangles how many rectangles are intersected
cout << "Total of:"<<" "<< intersect1 + intersect2 + intersect3 << "Rectangles intersect:" << endl;


return 0;
}
//........................................END.....................................//