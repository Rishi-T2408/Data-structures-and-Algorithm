// Sparse Matrix creation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct element {
    int i;
    int j;
    int x;
};   //This structure is used to make coordinate tuple of non zero values

struct Sparse
{
    int m;
    int n;
    int num;
    element* e;  //Pointer pointing to the array of tuples 
};

void create(Sparse *spr)
{
    cout << "Enter the dimentions of the matrix" << endl;
    cin >> spr->m >> spr->n;
    cout << "Enter the number of non zero values" << endl;
    cin >> spr->num;
    spr->e = new element[spr->num];
    for (int i = 0; i < spr->num; i++)
    {
        cout << "Enter the row number, column number and the key value of the non zero value" << endl;
        cin >> (spr->e[i]).i >> (spr->e[i]).j >> (spr->e[i]).x;
    }
}

void display(Sparse s)
{
    int k = 0;
    for (int p = 1; p <= s.m; p++) //As indexing of the real mathematical matrix starts from 1
    {
        for (int q = 1; q <= s.n; q++) {
            if ((p == s.e[k].i) && (q == s.e[k].j))
            {
                cout << (s.e[k++].x)<<" ";
            }
            else {
                cout << "0 ";
            }

        }
        cout << endl;
    }
}

int main()
{
    cout << "We are about to create an sparse matrix" << endl;
    Sparse s;
    create(&s);
    display(s);
    return 0;
}
