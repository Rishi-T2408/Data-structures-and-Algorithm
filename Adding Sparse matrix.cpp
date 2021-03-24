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

void create(Sparse* spr)
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
                cout << (s.e[k++].x) << " ";
            }
            else {
                cout << "0 ";
            }

        }
        cout << endl;
    }
}

Sparse* add(Sparse *s1,Sparse *s2)
{
    if ((s1->m == s2->m) && (s2->n == s2->n))
    {
        Sparse* sum;
        sum = new Sparse;
        int p, q, r;
        p = 0;
        q = 0;
        r = 0;
        sum->e = new element[s1->num + s2->num];
        while (p<(s1->num)&&q<(s2->num))
        {
            if ((s1->e[p]).i < (s2->e[q]).i)  //Then the first sparse matrix will have row number less
            {
                sum->e[r] = s1->e[p];
                r++;
                p++;
            }
            else if ((s1->e[p]).i > (s2->e[q]).i)
            {
                sum->e[r] = s2->e[q];
                r++;
                q++;
            }
            else {
                if ((s1->e[p]).j < (s2->e[q]).j)  
                {
                    sum->e[r] = s1->e[p];
                    r++;
                    p++;
                }
                else if ((s1->e[p]).j > (s2->e[q]).j)
                {
                    sum->e[r] = s2->e[q];
                    r++;
                    q++;
                }
                else {
                    (sum->e[r]).i = (s1->e[p]).i;
                    (sum->e[r]).j = (s1->e[p]).j;
                    (sum->e[r]).x = (s1->e[p]).x+ (s2->e[q]).x; //At the same row and the column number there will be addition of two sparse matrices
                    r++;
                    p++;
                    q++;
                }
            }
        }
        for (; p < s1->num; p++)
        {
            sum->e[r] = s1->e[p];
            r++;
        }
        for (; q < s2->num; q++)
        {
            sum->e[r] = s2->e[q];
            r++;
        }
        sum->m = s2->m;
        sum->n = s1->n;
        sum->num = r;
        return sum;
    }
    else {
        cout << "Matrices cannot be added" << endl;
        exit(1);
    }
}
int main()
{
    cout << "We are about to create an sparse matrix" << endl;
    Sparse s;
    Sparse* sum;
    create(&s);
    display(s);
    cout << "   +   "<<endl;
    Sparse s1;
    create(&s1);
    display(s1);

    sum = add(&s,&s1);
    cout << "___________________________________________________________________" << endl;
    display(*sum);
    return 0;
}


