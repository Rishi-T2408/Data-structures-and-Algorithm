// Anagram using hash table.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    char A[] = "listen";
    char B[] = "silent";
    int H[26] = { 0 };
    int j;
    int i;
    for (i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 'a']++;
    }
    for (j = 0; B[j] != '\0'; j++)
    {
        H[B[j] - 'a']--;
        if (H[B[j] - 'a'] < 0)
        {
            cout << "Not an anagram!!!" << endl;
        }
    }
    if (B[j] == '\0')
    {
        cout << "Anagram!!" << endl;
    }
    return 0;
}