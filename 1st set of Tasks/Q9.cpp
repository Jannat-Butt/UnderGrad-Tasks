#include<iostream>
using namespace std;
//function will input elements of Matrix 1
void input_arr1(int** arr1, int row1, int col1)
{
    for (int index = 0; index < row1; index++)
    {
        arr1[index] = new int[col1];
    }
    cout << "Enter values of Matrix 1" << endl;
    for (int indexi = 0; indexi < row1; indexi++)
    {
        for (int indexj = 0; indexj < col1; indexj++)
        {
            cin >> arr1[indexi][indexj];
        }

    }
}
//fuction will input elements of Matrix 2
void input_arr2(int** arr2, int row2, int col2)
{
    for (int i = 0; i < row2; i++)
    {
        arr2[i] = new int[col2];
    }
    cout << "Enter values of Matrix 2" << endl;
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            cin >> arr2[i][j];
        }
    }
}
//function will display elements of Matrix 1
void display_arr1(int** arr1, int row1, int col1)
{
    cout << "Matrix 1:" << endl;
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            cout << arr1[i][j] << " " << " ";
        }
        cout << endl;
    }
}
//function will display elements of Matrix 2
void display_arr2(int** arr2, int row2, int col2)
{
    cout << "Matrix 2" << endl;
    for (int indexi = 0; indexi < row2; indexi++)
    {
        for (int indexj = 0; indexj < col2; indexj++)
        {
            cout << arr2[indexi][indexj] << " " << " ";
        }
        cout << endl;
    }
}
//recursive function
int** multiplyMatrix(int row1, int col1, int A, int row2, int col2, int B)
{
    int dime = row1 * col2;
    int** C = new int*[dime];
    return C;
    delete[]C;
}
int main()
{
    int row1, col1, row2, col2;
    cout << "Enter rows of matrix 1:";
    cin >> row1;
    cout << "Enter cols of matrix 1:";
    cin >> col1;
    cout << "Enter rows of matrix 2:";
    cin >> row2;
    cout << "Enter cols of matrix 2:";
    cin >> col2;
    //dynamic array for matrix 1
    int** arr1 = new int* [row1];
    //dynamic array for matrix 2
    int** arr2 = new int* [row2];
    if (col1 != row2)
    {
        cout << "Multipliction not allowed as col1 is not equal to row2,execute again:";
    }
    else
    {
        //function call to input elements in array1(matrix 1)
        input_arr1(arr1, row1, col1);
        //function call to input elements in array2(matrix 2)
        input_arr2(arr2, row2, col2);

        //function call to display matrix1
        display_arr1(arr1, row1, col1);
        //function call to display matrix2
        display_arr2(arr2, row2, col2);
        //de-allocate array1

        for (int index = 0; index < row1; index++)
        {
            delete[] arr1[index];
        }
        delete[] arr1;
        arr1 = NULL;
        //de-allocate array2
        for (int index = 0; index < row2; index++)
        {
            delete[] arr2[index];
        }
        delete[] arr2;
        arr2 = NULL;
    }
}