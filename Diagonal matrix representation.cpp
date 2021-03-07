// Diagonal matrix using class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


class Diagonal {
private:
    int* A;
    int n;
public:
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }
    Diagonal()
    {
        n = 2;
        A = new int[n];
    }
    void set(int i, int j, int x);
    void get(int i, int j);
    void Display();
    ~Diagonal()
    {
        delete[]A;
    }
};

void Diagonal::set(int i, int j, int x)
{
    if (i == j)
    {
        A[i - 1] = x;
    }
}
void Diagonal::get(int i, int j)
{
    if (i == j)
    {
        cout << A[i - 1] << endl;
    }
    else {
        cout << 0 << endl;
    }
}

void Diagonal::Display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << A[i] << " " ;
            }
            else {
                cout << 0 << " ";
            }

        }
        cout << endl;
    }
}
int main()
{
    Diagonal m1(4);
    m1.set(1, 1, 5);
    m1.set(2, 2, 7);
    m1.set(3, 3, 9);
    m1.set(4, 4, 11);
    m1.get(2, 2);
    m1.get(1, 3);
    m1.Display();
    return 0;
}

