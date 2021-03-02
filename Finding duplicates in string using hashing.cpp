// Finding duplicates using an hash table in String.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	char A[] = "finding";
	int H['z' - 'a' + 1] = { 0 };  //Making hash table that takes count of small case alphabets
	for (int i = 0; A[i] != '\0'; i++)
	{
		H[A[i] - 'a']++;
	}

	for (int j = 0; j < ('z' - 'a' + 1); j++)
	{
		if (H[j] > 1)
		{
			printf("%c is dulpicated %d times\n", j + 97, H[j]);
		}
	}
	return 0;

}

