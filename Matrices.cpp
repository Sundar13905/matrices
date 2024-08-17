// sundaravadivelan karthikeyan 
// 23070123136
// Experiment 8: - To study and implement C++ 2D Array - Matrices


#include <iostream>
using namespace std;

void inputMat(int a[100][100], int rows, int col)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << "Enter element: (" << i + 1 << ", " << j + 1 << "): ";
            cin >> a[i][j];
        }
    }
}

void dispmat(int a[100][100], int rows, int col)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void addmat(int a1[100][100], int a2[100][100], int rows, int col)
{
    int add[100][100];
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < col; j++)
        {
            add[i][j] = a1[i][j] + a2[i][j]; 
        }
    }
    cout << "The addition of the two matrices is as follows: " << endl;
    dispmat(add, rows, col);
}

void diagonaladdmat(int a1[100][100], int a2[100][100], int rows, int col)
{
    int add[100][100] = {0};
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i == j)
            {
                add[i][j] = a1[i][j] + a2[i][j]; 
            }
        }
    }
    cout << "The diagonal addition of the two matrices is as follows: " << endl;
    dispmat(add, rows, col);
}

void mulmat(int b[100][100], int b1[100][100], int R1, int C1, int C2)
{
    int result[100][100] = {0};
    for(int i = 0; i < R1; i++)
    {
        for(int j = 0; j < C2; j++)
        {
            for(int k = 0; k < C1; k++)
            {
                result[i][j] += b[i][k] * b1[k][j];
            }
        }
    }
    cout << "The product of the two matrices is as follows: " << endl;
    dispmat(result, R1, C2);
}

void rowchecker(int rc[100][100], int row, int col)
{
    bool equal = true;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col - 1; j++)
        {
            if(rc[i][j] != rc[i][j+1])
            {
                equal = false;
                break;
            }
        }
        if(equal)
            cout << "Row " << i + 1 << " has all equal columns." << endl;
        else
            cout << "Row " << i + 1 << " does not have equal columns." << endl;
        equal = true;
    }
}

int main()
{
    int mat1[100][100], mat2[100][100];
    int choice;

    cout << "Press a key for the following operations: " << endl;
    cout << "1. Addition" << endl;
    cout << "2. Multiplication" << endl;
    cout << "3. Diagonal Addition" << endl;
    cout << "4. Comparing if columns in the same row are equal" << endl;
    cin >> choice;

    int r1, c1, r2, c2;

    switch (choice)
    {
        case 1:
            cout << "Enter the number of rows for the matrices: ";
            cin >> r1;
            cout << "Enter the number of columns for the matrices: ";
            cin >> c1;

            cout << "Enter the elements of the 1st matrix: " << endl;
            inputMat(mat1, r1, c1);
            cout << "Enter the elements of the 2nd matrix: " << endl;
            inputMat(mat2, r1, c1);

            addmat(mat1, mat2, r1, c1);
            break;

        case 2:
            cout << "Enter the number of rows for the 1st matrix: ";
            cin >> r1;
            cout << "Enter the number of columns for the 1st matrix: ";
            cin >> c1;
            cout << "Enter the number of rows for the 2nd matrix: ";
            cin >> r2;
            cout << "Enter the number of columns for the 2nd matrix: ";
            cin >> c2;

            if (c1 != r2) 
            {
                cout << "Matrix multiplication is not possible with these dimensions." << endl;
            } 
            else 
            {
                cout << "Enter the elements of the 1st matrix: " << endl;
                inputMat(mat1, r1, c1);
                cout << "Enter the elements of the 2nd matrix: " << endl;
                inputMat(mat2, r2, c2);
                mulmat(mat1, mat2, r1, c1, c2);
            }
            break;

        case 3:
            cout << "Enter the number of rows for the matrices: ";
            cin >> r1;
            cout << "Enter the number of columns for the matrices: ";
            cin >> c1;

            cout << "Enter the elements of the 1st matrix: " << endl;
            inputMat(mat1, r1, c1);
            cout << "Enter the elements of the 2nd matrix: " << endl;
            inputMat(mat2, r1, c1);

            diagonaladdmat(mat1, mat2, r1, c1);
            break;

        case 4:
            cout << "Enter the number of rows for the matrix: ";
            cin >> r1;
            cout << "Enter the number of columns for the matrix: ";
            cin >> c1;

            cout << "Enter the elements of the matrix: " << endl;
            inputMat(mat1, r1, c1);

            rowchecker(mat1, r1, c1);
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}
