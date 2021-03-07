// Class for lower triangular matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Column major

#include <iostream>
using namespace std;
class Matrix
{

    
public:
    int n;
    int* A;
    Matrix()
    {
        n = 2;
        A = new int[(n * (n + 1)) / 2];
    }
    Matrix(int n)
    {
        this->n = n;
        A = new int[(n * (n + 1)) / 2];

    }
    void setLTM( int i, int j, int x)  //LTM represents lower triangular matrix
    {
        if (i >= j)
        {
            A[(i * (i - 1) / 2) + j - 1] = x;

        }
    }

    void getLTM(int i, int j)
    {
        if (i < j)
            cout << 0 << endl;
        else
            cout << A[(i * (i - 1) / 2) + j - 1] << endl;

    }

    void DisplayLTM()
    {
        for (int i = 1; i <= (n); i++)
        {
            for (int j = 1; j <= (n); j++)
            {
                if (i >= j)
                    cout << A[(i * (i - 1) / 2) + j - 1] << " ";
                else {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }
    ~Matrix()
    {
        delete[]A;
    }

};



int main()
{
    Matrix m1(4);
    int key;
    cout << "Enter the values of matrix element row by row" << endl;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cin >> key;
            m1.A[(i * (i - 1) / 2) + j - 1] = key;
        }
        if(i!=4)
        cout << i << " Row scanned Enter next row" << endl;
    }
    m1.DisplayLTM();
    return 0;
}



