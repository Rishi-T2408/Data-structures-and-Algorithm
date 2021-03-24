// Intersection between 3 sets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int A[] = { 1,5,5 };
    int B[] = {3,4,5,5,10};
    int C[] = {5,5,10,20};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    int p = sizeof(C) / sizeof(int);
    int lenghtD = 0;
    int i = 0, j = 0,k=0;
    int* D;
    D = new int[15];
    while (i < m && j < n)
    {
        if (A[i] == B[j])
        {
            D[k++] = B[j++];
            lenghtD++;
        }
        else if (A[i] < B[j])
            i++;
        else
            j++;
    }
    cout << endl;
    int i1 = 0, j1 = 0, k1 = 0;
    int* Ans;
    Ans = new int[10];
    int lenghtAns = 0;
    while (i1 < lenghtD && j1 < p)   //Shitt yrr kyaa silli mistake krrhi brkrr dimaag kahrab
    {
        if (D[i1] == C[j1])
        {
            Ans[k1++] = C[j1++];
            lenghtAns++;
        }
        else if (D[i1] < C[j1])
            i1++;
        else
            j1++;
    }

    cout << "Intersection of three arrays is " << endl;
    for (int r = 0; r < lenghtAns; r++)
        cout << Ans[r] << "  ";

    return 0;
}







