// Hashing to find whether there are duplicates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int A[] = { 1,2,4,2,3,5,3,6,5,7,8,6,7,6 };
    int n = sizeof(A) / sizeof(int);
    int max = 8;
    int H[9] = { 0 };
    for (int i = 0; i < n; i++)  //Filling the hash table to see whether there are duplicates 
    {
        H[A[i]]++;
    }
    for (int j = 1; j < 9; j++)
    {
        if (H[j] > 1)
        {
            cout << j << " is duplicated " << H[j] << " times" << endl;
        }
    }
    return 0;
}