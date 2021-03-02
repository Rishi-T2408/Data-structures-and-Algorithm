// Finding duplicates using bitwise operator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    char A[] = "Manmohana";
    int H=0, X;  //H will provide the bits for the checking wheather there is duplicates or not
    for (int i = 0; A[i] != '\0'; i++)
    {
        X = 1;
        X = X << (A[i] - 'a');  //First checking wheather that bit is empty or not if it's empty fill it and if it's ON then dulicate present
        if ((H & X)==0)  //Masking
        {
            H = (H | X);   //Merging  
        }
        else {
            cout << A[i] << " is duplicated" << endl;
        }
      
    }
    return 0;
}
 

