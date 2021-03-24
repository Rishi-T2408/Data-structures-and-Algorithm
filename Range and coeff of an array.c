// Range and coeff of an array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdio.h>
using namespace std;
// Range=(max-min) and Coefficient=(max-min)/(max+Min)

int main()
{
	int A[] = { 15,16,10,9,6,7,17 };
	int lenght = sizeof(A) / sizeof(int);
	int min = A[0];
	int max = A[0];
	for (int i = 0; i < lenght; i++)
	{
		if (A[i] < min)
		{
			min = A[i];
		}
		else if (A[i] > max)
		{
			max = A[i];
		}
		

	}
	printf("Range of array is %d\n", (max - min));
	printf("Coeff of array is %f\n", ((float(max) - min) / (float(max) + min)));
	return 0;
}

