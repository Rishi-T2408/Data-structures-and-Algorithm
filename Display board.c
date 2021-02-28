

#include <iostream>
#include<stdio.h>
using namespace std;
void LinkedIn(char *A, int lenght)
{
    char ram[100];
    int temp=A[0],i;
    for (i = 1; i < lenght; i++)
    {
        A[i-1] = A[i];   //Big silly mistake isliye thoda sa aalysis krna chahiye
    }
    A[i-1] = temp;
    for(i = 0; i < lenght; i++)
    {
        cout << A[i] << "";
    }
    for (int c = 1; c <= 9999; c++)
    {
        for (int d = 1; d <= 3276; d++)
        {
        }
    }
    
   
   
}
int main()
{
    char Link[100]="  Being crazy with data structures............#C++ Code";
    
    int lenght = 75,i;
    int j=0;
   while (j<100)
    {
        for (int c = 1; c <= 9999; c++)
        {
            for (int d = 1; d <= 3276; d++)
            {
            }
        }
        system("CLS");
        LinkedIn(Link, lenght); //Array name or the string name is base address of arrya
       
    }

}


