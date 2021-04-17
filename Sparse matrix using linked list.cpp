// Sparse matrix using linked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Node
{
    int col;
    int val;
    Node* next;
}*last=NULL;
int main()
{
    int m, n,none,colnum,value;
    cout << "Enter the number of rows and columns in an sparse matrix" << endl;
    cin >> m;
    cin >> n;
    cout << m;
    Node** A;  //Array of linked lists
    A = new Node * [m];
    cout << "Creating sparse matrix now" << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "Enter the number of none zero elements in " << i << "th row" << endl;
        cin >> none;
        if (none == 0)
        {
            A[i] = NULL;
            continue;
        }
        else {
            for (int j = 0; j < none; j++)
            {
                if (j == 0)
                {
                    cout << "Enter the column number and data value of non zero value" << endl;
                    cin >> colnum;
                    cin >> value;
                    Node *t = new Node;
                    t->val = value;
                    t->col = colnum;
                    A[i] = t;
                    last = t;
                    last->next = NULL;
                }
                else {
                    cout << "Enter the column number and data value of non zero value" << endl;
                    cin >> colnum;
                    cin >> value;
                    Node* t = new Node;
                    t->val = value;
                    t->col = colnum;
                    last->next = t;
                    last = t;
                    t->next = NULL;
                }
               
            }
        }
    }
    cout << "Now displaying sparse matrix" << endl;
    for (int i = 0; i < m; i++)
    {
        Node* p = A[i];
        for (int j = 0; j < n; j++)
        {
            if (p != NULL)
            {
                if (j == p->col)
                {
       
                    cout << p->val << " ";
                    p = p->next;
                    
                }
                else {
                    cout << "0 ";
                }
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return 0;
}

