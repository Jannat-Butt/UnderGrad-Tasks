#include<iostream>
#include"Q5.h"
using namespace std;
int main()
{
	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17;
	cout << "Enter 4 values for 2x2 matrix:" << endl;
	cin >> n1 >> n2 >> n3 >> n4;
	Matrix m1(n1, n2, n3, n4);
	cout << "Enter values for 3x3 matrix:" << endl;
	cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8 >> n9;
	Matrix m2(n1, n2, n3, n4, n5, n6, n7, n8, n9);
	cout << "Enter values for 4x4 matrix:" << endl;
	cin >> n1 >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8 >> n9 >> n10 >> n11 >> n12 >> n13 >> n14 >> n15 >> n16;
	Matrix m3(n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16);

	cout << "Matrix 2x2" << endl;
	m1.show();
	cout << endl;
	cout << "Matrix 3x3" << endl;
	m2.show();
	cout << endl;
	cout << "Matrix 4x4" << endl;
	m3.show();
	cout << endl;

	cout << "matrix 2x2 row:" << m1.getRows() << endl;
	cout << "Matrix 3x3 row:" << m2.getRows() << endl;
	cout << "Matrix 4x4 row:" << m3.getRows() << endl;
	cout << endl;
	cout << "matrix 2x2 col:" << m1.getCol() << endl;
	cout << "Matrix 3x3 col:" << m2.getCol() << endl;
	cout << "Matrix 4x4 col:" << m3.getCol() << endl;

	cout << endl;
	cout << "Select row [0,1,2,3] and column [0,1,2,3] to find value: " << endl;
	cin >> n1 >> n2;
	//getting a value at particular index
	if (n1 <= 1 && n2 <= 1)
	{

		cout << "Value at 2x2 is:" << m1.getValue(n1, n2) << endl;
		cout << "Value at 3x3 is:" << m2.getValue(n1, n2) << endl;
		cout << "Value at 4x4 is:" << m3.getValue(n1, n2) << endl;


	}
	else if (n1 <= 2 && n2 <= 2)
	{
		cout << "Value at 3x3 is:" << m2.getValue(n1, n2) << endl;
		cout << "Value at 4x4 is:" << m3.getValue(n1, n2) << endl;


	}
	else if (n1 <= 3 && n2 <= 3)
	{
		cout << "Value at 4x4 is" << m3.getValue(n1, n2) << endl;

	}
	else
		cout << "You entered greater rows and columns that donot match 2x2 3x3 or 4x4 matrix" << endl;

	cout << "Select row [0,1,2,3] and column [0,1,2,3] to set a value " << endl;
	cin >> n1 >> n2;
	cout << "Enter a value you want to set:" << endl;
	cin >> n3;
	//Setting value at particular index
	if (n1 <= 1 && n2 <= 1)
	{
		m1.setValue(n1, n2, n3);
		m2.setValue(n1, n2, n3);
		m3.setValue(n1, n2, n3);
		cout << ".......Value setted....." << endl;
	}
	else if (n1 <= 2 && n2 <= 2)
	{
		m2.setValue(n1, n2, n3);
		m3.setValue(n1, n2, n3);
		cout << ".......Value setted....." << endl;
	}
	else if (n1 <= 3 && n2 <= 3)
	{
		m3.setValue(n1, n2, n3);
		cout << ".......Value setted....." << endl;
	}
	else
		cout << "You entered greater rows and columns that donot match 2x2 3x3 or 4x4 matrix" << endl;

	cout << endl;

	cout << "Values after set:" << endl;
	cout << "Matrix 2x2" << endl;
	m1.show();
	cout << endl;
	cout << "Matrix 3x3" << endl;
	m2.show();
	cout << endl;
	cout << "Matrix 4x4" << endl;
	m3.show();
	cout << endl;

	cout << "Sum of Elements in 2x2 is:" << m1.Total() << endl;
	cout << "Sum of Elements in 3x3 is:" << m2.Total() << endl;
	cout << "Sum of Elements in 4x4 is:" << m3.Total() << endl;
	cout << endl;

	cout << "Average of Elements in 2x2 is:" << m1.Average() << endl;
	cout << "Average of Elements in 3x3 is:" << m2.Average() << endl;
	cout << "Average of Elements in 4x4 is:" << m3.Average() << endl;
	cout << endl;

	cout << "Enter row to calculate sum of that row:" << endl;
	cin >> n1;
	if (n1 <= 1)
	{
		cout << "Sum of 2x2 Matrix:" << m1.RowTotal(n1) << endl;
		cout << "Sum of 3x3 Matrix:" << m2.RowTotal(n1) << endl;
		cout << "Sum of 4x4 Matrix:" << m3.RowTotal(n1) << endl;
	}
	else if (n1 <= 2)
	{
		cout << "Sum of 3x3 Matrix:" << m2.RowTotal(n1) << endl;
		cout << "Sum of 4x4 Matrix:" << m3.RowTotal(n1) << endl;
	}
	else if (n1 <= 3)
	{
		cout << "Sum of 4x4 Matrix:" << m3.RowTotal(n1) << endl;

	}
	else
		cout << "You entered greater rows and columns that donot match 2x2 3x3 or 4x4 matrix" << endl;
	cout << endl;


	cout << "Enter column to calculate sum of that column:" << endl;
	cin >> n1;
	if (n1 <= 1)
	{
		cout << "sum of 2x2 Matrix:" << m1.ColumnTotal(n1) << endl;
		cout << "Sum of 3x3 Matrix:" << m2.ColumnTotal(n1) << endl;
		cout << "Sum of 4x4 Matrix:" << m3.ColumnTotal(n1) << endl;
	}
	else if (n1 <= 2)
	{
		cout << "Sum of 3x3 Matrix:" << m2.ColumnTotal(n1) << endl;
		cout << "Sum of 4x4 Matrix:" << m3.ColumnTotal(n1) << endl;
	}
	else if (n1 <= 3)
	{
		cout << "Sum of 4x4 Matrix:" << m3.ColumnTotal(n1) << endl;

	}
	else
		cout << "You entered greater rows and columns that donot match 2x2 3x3 or 4x4 matrix" << endl;
	cout << endl;

	cout << "Enter Row to find highest entry:";
	cin >> n1;

	if (n1 <= 1)
	{
		cout << "Largest element in" << " " << n1 << " " << "Row of 2x2 Matrix : " << m1.HighestInRow(n1) << endl;
		cout << "Largest element in" << " " << n1 << " " << "Row of 3x3 Matrix : " << m2.HighestInRow(n1) << endl;
		cout << "Largest element in" << " " << n1 << " " << "Row of 4x4 Matrix : " << m3.HighestInRow(n1) << endl;
	}
	else if (n1 <= 2)
	{
		cout << "Largest element in" << " " << n1 << " " << "Row of 3x3 Matrix : " << m2.HighestInRow(n1) << endl;
		cout << "Largest element in" << " " << n1 << " " << "Row of 4x4 Matrix : " << m3.HighestInRow(n1) << endl;
	}
	else if (n1 <= 3)
	{
		cout << "Largest element in" << " " << n1 << " " << "Row of 4x4 Matrix : " << m3.HighestInRow(n1) << endl;
	}
	else
		cout << "You entered greater rows and columns that donot match 2x2 3x3 or 4x4 matrix" << endl;

	cout << endl;

	cout << "Enter Row to find lowest entry:";
	cin >> n1;

	if (n1 <= 1)
	{
		cout << "Lowest element in" << " " << n1 << " " << "Row of 2x2 Matrix : " << m1.LowestInRow(n1) << endl;
		cout << "Lowest element in" << " " << n1 << " " << "Row of 3x3 Matrix : " << m2.LowestInRow(n1) << endl;
		cout << "Lowest element in" << " " << n1 << " " << "Row of 4x4 Matrix : " << m3.LowestInRow(n1) << endl;
	}
	else if (n1 <= 2)
	{
		cout << "Lowest element in" << " " << n1 << " " << "Row of 3x3 Matrix : " << m2.LowestInRow(n1) << endl;
		cout << "Lowest element in" << " " << n1 << " " << "Row of 4x4 Matrix : " << m3.LowestInRow(n1) << endl;
	}
	else if (n1 <= 3)
	{
		cout << "Lowest element in" << " " << n1 << " " << "Row of 4x4 Matrix : " << m3.LowestInRow(n1) << endl;
	}
	else
		cout << "You entered greater rows and columns that donot match 2x2 3x3 or 4x4 matrix" << endl;

	cout << endl;

	cout << "Sum of 2x2 Left Diagonal:" << m1.LeftDiagonalTotal() << endl;
	cout << "Sum of 3x3 Left Diagonal:" << m2.LeftDiagonalTotal() << endl;
	cout << "Sum of 4x4 Left Diagonal:" << m3.LeftDiagonalTotal() << endl;
	cout << endl;
	cout << "Sum of 2x2 right Diagonal:" << m1.RightDiagonalTotal() << endl;
	cout << "Sum of 3x3 right Diagonal:" << m2.RightDiagonalTotal() << endl;
	cout << "Sum of 4x4 right Diagonal:" << m3.RightDiagonalTotal() << endl;

	cout << "Enter value of K:";
	cin >> n1;
	cout << "In 2x2 Matrix kth smallest is:" << m1.FindkSmallest(n1) << endl;
	cout << "In 3x3 Matrix kth smallest is:" << m2.FindkSmallest(n1) << endl;
	cout << "In 4x4 Matrix kth smallest is:" << m3.FindkSmallest(n1) << endl;

	cout << "Enter value of K:";
	cin >> n1;
	cout << "In 2x2 Matrix kth largest is:" << m1.FindkLargest(n1) << endl;
	cout << "In 3x3 Matrix kth largest is:" << m2.FindkLargest(n1) << endl;
	cout << "In 4x4 Matrix kth largest is:" << m3.FindkLargest(n1) << endl;



	cout << "Transpose of 2x2 Matrix..This is now the resultant Matrix:" << endl;
	m1.Transpose();
	m1.show();

	cout << "Transpose of 3x3 Matrix..This is now the resultant Matrix:" << endl;
	m2.Transpose();
	m2.show();

	cout << endl;

	cout << "Transpose of 4x4 Matrix..This is now the resultant Matrix:" << endl;
	m3.Transpose();
	m3.show();
	cout << endl;



	cout << "To Add 2X2 Matrix type 2:" << endl << "To Add 3x3 Matrix type 3:" << endl << "To Add 4x4 Matrix type 4:" << endl;
	cin >> n1;
	if (n1 == 2)
	{
		cout << "Enter 4 Entries of 2x2 matrix" << endl;
		cin >> n2 >> n3 >> n4 >> n5;
		Matrix addition1(n2, n3, n4, n5);
		m1.Add(addition1);
		cout << "Addition is..This is now origional Matrix:" << endl << endl;
		m1.show();
		cout << endl;
	}
	else if (n1 == 3)
	{
		cout << "Enter 9 Entries of 3x3 matrix" << endl;
		cin >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8 >> n9 >> n10;
		Matrix addition1(n2, n3, n4, n5, n6, n7, n8, n9, n10);
		m2.Add(addition1);
		cout << "Addition is..This is now origional Matrix:" << endl << endl;
		m2.show();
		cout << endl;
	}
	else if (n1 == 4)
	{
		cout << "Enter 16 Entries of 4x4 matrix" << endl;
		cin >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8 >> n9 >> n10 >> n11 >> n12 >> n13 >> n14 >> n15 >> n16 >> n17;
		Matrix addition1(n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17);
		m3.Add(addition1);
		cout << "Addition is..This is now origional Matrix:" << endl << endl;
		m3.show();
		cout << endl;
	}


	cout << "To subtract 2X2 Matrix type 2:" << endl << "To subtract 3x3 Matrix type 3:" << endl << "To subtract 4x4 Matrix type 4:" << endl;
	cin >> n1;
	if (n1 == 2)
	{
		cout << "Enter 4 Entries of 2x2 matrix" << endl;
		cin >> n2 >> n3 >> n4 >> n5;
		Matrix subtraction1(n2, n3, n4, n5);
		m1.Subtract(subtraction1);
		cout << "subtraction is..This is now origional Matrix:" << endl << endl;
		m1.show();
		cout << endl;
	}
	else if (n1 == 3)
	{
		cout << "Enter 9 Entries of 3x3 matrix" << endl;
		cin >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8 >> n9 >> n10;
		Matrix subtraction1(n2, n3, n4, n5, n6, n7, n8, n9, n10);
		m2.Subtract(subtraction1);
		cout << "subtraction is..This is now origional Matrix:" << endl << endl;
		m2.show();
		cout << endl;
	}
	else if (n1 == 4)
	{
		cout << "Enter 16 Entries of 4x4 matrix" << endl;
		cin >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8 >> n9 >> n10 >> n11 >> n12 >> n13 >> n14 >> n15 >> n16 >> n17;
		Matrix subtraction1(n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17);
		m3.Subtract(subtraction1);
		cout << "subtraction is..This is now origional Matrix:" << endl << endl;
		m3.show();
		cout << endl;
	}


	cout << "To Multiply 2X2 Matrix type 2:" << endl << "To Multiply 3x3 Matrix type 3:" << endl << "To Multiply 4x4 Matrix type 4:" << endl;
	cin >> n1;
	if (n1 == 2)
	{
		cout << "Enter 4 Entries of 2x2 matrix" << endl;
		cin >> n2 >> n3 >> n4 >> n5;
		Matrix multip(n2, n3, n4, n5);
		m1.Multiply(multip);
		cout << "subtraction is..This is now origional Matrix:" << endl << endl;
		m1.show();
		cout << endl;
	}
	else if (n1 == 3)
	{
		cout << "Enter 9 Entries of 3x3 matrix" << endl;
		cin >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8 >> n9 >> n10;
		Matrix multip(n2, n3, n4, n5, n6, n7, n8, n9, n10);
		m2.Multiply(multip);
		cout << "subtraction is..This is now origional Matrix:" << endl << endl;
		m2.show();
		cout << endl;
	}
	else if (n1 == 4)
	{
		cout << "Enter 16 Entries of 4x4 matrix" << endl;
		cin >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8 >> n9 >> n10 >> n11 >> n12 >> n13 >> n14 >> n15 >> n16 >> n17;
		Matrix multip(n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17);
		m3.Multiply(multip);
		cout << "subtraction is..This is now origional Matrix:" << endl << endl;
		m3.show();
		cout << endl;
	}

	cout << "To Merge 2X2 Matrix type 2:" << endl << "To Merge 3x3 Matrix type 3:" << endl << "To Merge 4x4 Matrix type 4:" << endl;
	cin >> n1;
	if (n1 == 2)
	{
		cout << "Enter 4 Entries of 2x2 matrix" << endl;
		cin >> n2 >> n3 >> n4 >> n5;
		Matrix mrge(n2, n3, n4, n5);
		cout << "  ........2x2 matrix is.........:" << endl;
		m1.show();
		cout << endl << "  ........I have merged your matrix .........:" << endl;
		Matrix result;
		result = m1.merge(mrge);
		result.show();
		cout << endl;
	}
	else if (n1 == 3)
	{
		cout << "Enter 9 Entries of 3x3 matrix" << endl;
		cin >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8 >> n9 >> n10;
		Matrix mrge(n2, n3, n4, n5, n6, n7, n8, n9, n10);
		cout << "  ........ Origional 3x3 matrix is.........:" << endl;
		m2.show();
		cout << endl << "  ........I have merged your matrix .........:" << endl;
		Matrix result;
		result = m2.merge(mrge);
		result.show();
		cout << endl;
	}
	else if (n1 == 4)
	{
		cout << "Enter 16 Entries of 4x4 matrix" << endl;
		cin >> n2 >> n3 >> n4 >> n5 >> n6 >> n7 >> n8 >> n9 >> n10 >> n11 >> n12 >> n13 >> n14 >> n15 >> n16 >> n17;
		Matrix mrge(n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16, n17);
		cout << "  ........ Origional 4x4 matrix is.........:" << endl;
		m3.show();
		cout << endl << "  ........I have merged your matrix .........:" << endl;
		Matrix result;
		result = m3.merge(mrge);
		result.show();
		cout << endl;
	}
	return 0;

}