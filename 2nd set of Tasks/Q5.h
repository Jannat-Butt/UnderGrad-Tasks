using namespace std;
class Matrix
{
private:
	int** matrix;
	int row;
	int col;

public:
	Matrix();
	Matrix(int, int, int, int, int, int);
	Matrix(int, int, int, int, int, int, int, int, int, int, int);
	Matrix(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
	Matrix(int, int);
	int getRows()const;
	int getCol()const;
	void setValue(int, int, int);
	int getValue(int, int);
	int Total();
	double Average();
	int RowTotal(int);
	int ColumnTotal(int);
	void show();
	int HighestInRow(int row);
	int LowestInRow(int);
	int LeftDiagonalTotal();
	int RightDiagonalTotal();
	int FindkSmallest(int k);
	int FindkLargest(int k);
	Matrix Transpose();
	Matrix Add(Matrix m);
	Matrix Subtract(Matrix m);
	Matrix Multiply(Matrix m);
	Matrix(const Matrix& mat);
	Matrix merge(Matrix m);
	//~Matrix();

};
Matrix::Matrix(int n1, int n2, int n3, int n4, int row = 2, int col = 2)
{
	//assign parametere row to caller obj row 
	this->row = row;
	//assign parametere col to caller obj col 
	this->col = col;

	matrix = new int* [row];
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}
	//manually assigning 2x2 matrix 
	matrix[0][0] = n1;
	matrix[0][1] = n2;
	matrix[1][0] = n3;
	matrix[1][1] = n4;

}
Matrix::Matrix()
{}
Matrix::Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int
	row = 3, int col = 3)
{
	//assign parametere row to caller obj row 
	this->row = row;
	//assign parametere col to caller obj col 
	this->col = col;
	//dynamically allocate matrix 3d
	matrix = new int* [row];
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}
	//manually assigning 3x3 matrix 
	matrix[0][0] = n1;
	matrix[0][1] = n2;
	matrix[0][2] = n3;
	matrix[1][0] = n4;
	matrix[1][1] = n5;
	matrix[1][2] = n6;
	matrix[2][0] = n7;
	matrix[2][1] = n8;
	matrix[2][2] = n9;
}
Matrix::Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9, int
	n10, int n11, int n12, int n13, int n14, int n15, int n16, int row = 4, int col =
	4)
{

	//assign parametere row to caller obj row 
	this->row = row;
	this->col = col;
	//assign parametere col to caller obj col 
	matrix = new int* [row];
	//dynamically allocate matrix 4d
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}
	//manually assigning 4x4 matrix 
	matrix[0][0] = n1;  matrix[0][1] = n2;   //at 00  01
	matrix[0][2] = n3;  matrix[0][3] = n4;//at 02 03
	matrix[1][0] = n5;  matrix[1][1] = n6;//at 10  11
	matrix[1][2] = n7;  matrix[1][3] = n8;//at 12  13
	matrix[2][0] = n9;  matrix[2][1] = n10;//at 20  21
	matrix[2][2] = n11; matrix[2][3] = n12;//at 22  23
	matrix[3][0] = n13; matrix[3][1] = n14;//at 30  31
	matrix[3][2] = n15; matrix[3][3] = n16;//at 32  33
}
//dynamically assigning the rows and col(x,y)
//to matrix and creating new matrix of size x y
Matrix::Matrix(int x, int y)
{
	this->row = x;
	this->col = y;
	matrix = new int* [this->row];
	for (int i = 0; i < this->row; i++)
	{
		matrix[i] = new int[this->col];
	}

}
//getting rows 
int Matrix::getRows()const
{
	return row;
}
//geting columns
int Matrix::getCol()const
{
	return col;
}
//user will enter specific value and 
//based on those row and col
//this func will return value at specific entry
int Matrix::getValue(int row, int col)
{
	int value = matrix[row][col];
	return value;
}

void Matrix::setValue(int row, int col, int value)
{
	//user will enter value to be set at row and col
	//this will set that value at that particular index
	matrix[row][col] = value;
}
//this will count toatl
int Matrix::Total()
{
	int sum = 0;
	for (int i = 0; i < this->row; i++)
	{
		//traversing through row
		for (int j = 0; j < this->col; j++)
		{
			//traversing through col
			//each entry will be added
			sum = sum + matrix[i][j];
		}
	}
	//sum is returned
	return sum;
}
double Matrix::Average()
{
	float sum = 0;
	for (int i = 0; i < this->row; i++)
	{//traversing through row
		for (int j = 0; j < this->col; j++)
		{
			//traversing through col
			sum = sum + matrix[i][j];
			//each entry will be added
		}
	}
	//after calculating sum 
	//avg wil be calculated
	double avg = sum / (this->row * this->col);
	//returning avg
	return avg;
}
//toatl sum of entries in row
int Matrix::RowTotal(int row)
{
	int sum = 0;
	for (int j = 0; j < this->row; j++)
	{
		//user has given row
		//loop is executing till row and
		//sum is doing plus to 
		//each entry found
		sum = sum + matrix[row][j];
	}
	//returning sum
	return sum;
}
//calculate toatal sum of particular col
int Matrix::ColumnTotal(int col)
{
	int sum = 0;
	//loop is executing till col 
	for (int j = 0; j < this->col; j++)
	{
		//user has given col
		sum = sum + matrix[j][col];
		//sum is doing plus to 
		//each entry found at col
	}

	//returning sum
	return sum;
}
//display function
void Matrix::show()
{
	for (int i = 0; i < this->row; i++)
	{
		//row loop
		for (int j = 0; j < this->col; j++)
		{
			//col loop
			cout << matrix[i][j] << " ";
			//display ith jth entry
		}
		cout << endl;
	}
}
//finding highest entry in a roe
int Matrix::HighestInRow(int row)
{
	int greater = 0;
	for (int j = 0; j < this->row; j++)
	{
		if (matrix[row][j] > greater)
		{
			//as greater is 0 
			//means if value at that particular row will be 
			//greater than 0
			greater = matrix[row][j];
			//means greater will now carry that greater value
		}
		//loop will keep on executing till it finds highest entry/value
	}
	return greater;
}
////finding lowest entry in a row
int Matrix::LowestInRow(int row)
{
	int smallest = matrix[row][0];
	//smallest having entry of particular row but 0th col
	for (int j = 0; j < this->row; j++)
	{
		if (matrix[row][j] < smallest)
		{
			//if the entry at specific row and jth index 
			//is less than entry of particular row at 0th col
			smallest = matrix[row][j];
			//than smallest will store that smaller value
		}
	}
	//returning smallest value
	return smallest;
}
//cal sum of left diagonal (\)
int Matrix::LeftDiagonalTotal()
{
	int sum = 0;
	for (int i = 0; i < this->row; i++)
	{
		//loop through row
		for (int j = 0; j < this->col; j++)
		{
			//loop for col
			if (i == j)
			{
				//thsi is saying that if ith and jth entry is equal
				sum = sum + matrix[i][j];
				//that means that is left diagobal
			    //and than sum will be sum +
			}
		}
	}
	//return sum
	return sum;
}
//cal sum of right diagonal (/)
int Matrix::RightDiagonalTotal()
{
	int sum = 0;
	for (int indexi = 0; indexi < this->row; indexi++)
	{
		//loop through row
		for (int jthindex = 0; jthindex < this->col; jthindex++)
		{
			//loop for col
			if ((indexi + jthindex) == (this->row - 1))
			{
				//thsi is saying that if ith and jth index will 
				//be equal to the row -1 of caller obj 
				sum = sum + matrix[indexi][jthindex];
				//this means this is right diagobal
			}
		}
	}
	//returning sum
	return sum;
}
//this will find smallest entry that user enters k
int Matrix::FindkSmallest(int k)
{
	int counter = 1;
	for (int i1 = 0; i1 < this->row; i1++)
	{
		//outer loop through row
		for (int j1 = 0; j1 < this->col; j1++)
		{
			//outer loop through col
			for (int i = 0; i < this->row; i++)
			{
				//inner loop through row
				for (int j = 0; j < this->col; j++)
				{
					//inner loop through cols
					if (this->matrix[i1][j1] < this->matrix[i][j])
					{
						//checks if ith and jth entry is less than
						//entry of caller obj ith and jth entry 
						int temp = this->matrix[i1][j1];
						this->matrix[i1][j1] = this->matrix[i][j];
						this->matrix[i][j] = temp;
						//temp is made for swapping
						//as temp=a;
						//a=b;
						//b=temp
					}
				}
			}
		}
	}
	//loop through row
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{//loop through col
			if (counter == k)
			{
				//counter will check if i have achieved kth value that user enters
				return this->matrix[i][j];
				//if fount that k than at that point it will return ith and jth entry
			}
			//counter is incremented
			counter++;
		}
	}
	return 0;
}
//this will find k largest
int Matrix::FindkLargest(int k)
{
	int counter = 1;
	//loop for row 
	for (int i = (this->row - 1); i >= 0; i--)
	{
		//loop through row
		for (int j = (this->col - 1); j >= 0; j--)
		{
			//loop for col
			if (counter == k)
			{
				//this will basically as copy of above code
				//but here loop is starting from row eg. 5 to 0
				return this->matrix[i][j];
				//but here loop is starting from col eg. 5 to 0
			}
			//counter is incremented
			counter++;
		}
	}
	return 0;
}

//transpose 
Matrix Matrix::Transpose()
{
	//dynamically alloacte 2d array
	int** holdtemp = new int* [this->row];
	//of size as caller obj
	for (int i = 0; i < this->row; i++)
	{
		holdtemp[i] = new int[this->col];
	}
	//loop row
	for (int i = 0; i < this->row; i++)
	{
		//loop col
		for (int j = 0; j < this->col; j++)
		{
			//holdtemp will store values of matrix that is caller obj matrixx
			holdtemp[i][j] = this->matrix[i][j];
		}
		cout << endl;
	}

	//this is transpose
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			//the origional caller matrix will store
			//ith and jth index values on jth and ith indexes
			this->matrix[j][i] = holdtemp[i][j];
		}
	}

	return  (*this);
	//releasing memory
	for (int i = 0; i < this->row; i++)
	{
		delete[]holdtemp[i];
	}
	delete[]holdtemp;
}


Matrix Matrix::Add(Matrix m)
{
	int** holdOrigionalMatrix = new int* [this->row];
	//creating dynamic array
	for (int i = 0; i < this->row; i++)
	{
		holdOrigionalMatrix[i] = new int[this->col];
	}
	//assigning dynamic array the origional this->array
	for (int indexi = 0; indexi < this->row; indexi++)
	{
		for (int jthindex = 0; jthindex < this->col; jthindex++)
		{
			holdOrigionalMatrix[indexi][jthindex] = this->matrix[indexi][jthindex];
		}
	}

	//performing addition
	for (int indexi = 0; indexi < this->row; indexi++)
	{
		for (int jthindex = 0; jthindex < this->col; jthindex++)
		{
			//adding in the origional caller obj matrix to the holdtemp which has this->matrix
			//plus the parametre matrix
			this->matrix[indexi][jthindex] = holdOrigionalMatrix[indexi][jthindex] + m.matrix[indexi][jthindex];
		}
	}
	//returning the origioanal matrix
	return (*this);
	//releasing memory
	for (int i = 0; i < this->row; i++)
	{
		delete[]holdOrigionalMatrix[i];
	}
	delete[]holdOrigionalMatrix;
}

Matrix Matrix::Subtract(Matrix m)
{
	int** holdOrigionalMatrix = new int* [this->row];
	//creating dynamic array
	for (int i = 0; i < this->row; i++)
	{
		holdOrigionalMatrix[i] = new int[this->col];
	}
	//assigning dynamic array the origional this->array
	for (int indexi = 0; indexi < this->row; indexi++)
	{
		for (int jthindex = 0; jthindex < this->col; jthindex++)
		{
			//assign holdtem the origiobal matrix
			holdOrigionalMatrix[indexi][jthindex] = this->matrix[indexi][jthindex];
		}
	}

	//performing subtraction
	for (int indexi = 0; indexi < this->row; indexi++)
	{
		for (int jthindex = 0; jthindex < this->col; jthindex++)
		{
			//subtracting in the origional caller obj matrix to the holdtemp which has this->matrix
			//- the parameter matrix
			this->matrix[indexi][jthindex] = holdOrigionalMatrix[indexi][jthindex] - m.matrix[indexi][jthindex];
		}
	}
	//returning the matrix whivh the caller has caled obj basically
	return (*this);
	//releasing memory
	for (int i = 0; i < this->row; i++)
	{
		delete[]holdOrigionalMatrix[i];
	}
	delete[]holdOrigionalMatrix;
}
//func for multiplying matrices
Matrix Matrix::Multiply(Matrix m)
{
	//2d array for holding this->matrix caller
	int** holdOrigionalMatrix = new int* [this->row];
	//creating dynamic array
	for (int i = 0; i < this->row; i++)
	{
		holdOrigionalMatrix[i] = new int[this->col];
	}
	//assigning dynamic array the origional this->array
	for (int indexi = 0; indexi < this->row; indexi++)
	{
		for (int indexj = 0; indexj < this->col; indexj++)
		{
			//assign this->entries to holdorig
			holdOrigionalMatrix[indexi][indexj] = this->matrix[indexi][indexj];
			//index by index
		}
	}

	//performing Multiplication
	for (int indexi = 0; indexi < this->row; indexi++)
	{
		for (int indexj = 0; indexj < this->col; indexj++)
		{

			//Multiplying in the origional caller obj matrix to the holdtemp which has this->matrix
			//* the parameter matrix
			this->matrix[indexi][indexj] = holdOrigionalMatrix[indexi][indexj] * m.matrix[indexi][indexj];
		}
	}
	//returning the caller obj
	return (*this);
	//releasing memory
	for (int i = 0; i < this->row; i++)
	{
		delete[]holdOrigionalMatrix[i];
	}
	delete[]holdOrigionalMatrix;
}
//here we are recieving obj as parametre
Matrix::Matrix(const Matrix& mat)
{
	col = mat.col;
	row = mat.row;
	matrix = new int* [row];
	//dynamic create array of size row col
	for (int i = 0; i < row; i++)
	{
		matrix[i] = new int[col];
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			//assigning parametre matrix index by index to the dynamic array
			matrix[i][j] = mat.matrix[i][j];
		}
	}
}
//this will merge the two matrix
Matrix Matrix::merge(Matrix m)
{
	int column = 2 * this->col;
	//column will have double of the caller obj columns
	Matrix tempTostore(this->row, column);
	//obj of Matrix than will initialize row and col matrix
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			//temp is obj of matrix this will call the private member (matrix)
			//and on temp matrix ith jth it will store the caller objs matrix ith jth entry
			tempTostore.matrix[i][j] = this->matrix[i][j];
			//as it is merging so row will remain same bu jth enty multiply by
			tempTostore.matrix[i][j + this->col] = m.matrix[i][j];
			//the number of columns of the caller obj 
			//at that col it will store the parametre matrix ith jth index entry
		}
	}
	//returns obj of Matrix
	return tempTostore;

}
/*
Matrix::~Matrix()
{
	for (int ind = 0; ind <this->row; ind++)
	{
		delete[]matrix[ind];
	}
	delete[]matrix;
	cout << "Program ends Destructor called:";
}*/
