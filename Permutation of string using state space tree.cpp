// Permutation of string using state space tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void perm(char S[], int k)
{
	static int A[10] = { 0 };
	static char res[10];
	int i;
	if (S[k] == '\0')
	{
		res[k] = '\0';
		cout << res << endl;
	}
	else {
		for (i = 0; S[i] != '\0'; i++)
		{
			if (A[i] == 0)
			{
				res[k] = S[i];
				A[i] = 1;
				perm(S, k + 1);
				A[i] = 0;
			}
		}
	}
}
int main()
{
	char S[] = "rishi";
	perm(S, 0);
	return 0;

}

