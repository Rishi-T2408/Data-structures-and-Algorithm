// Stack using linked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
}*top=NULL;
void push(int x)
{
    Node* t = new Node;
    if (t != NULL)
    {
        t->data = x;
        t->next = top;
        top = t;

        t = NULL;
    }
    else {
        cout << "Stack overflow" << endl;
    }
}
void DisplayS()
{
    Node* p = top;
    while (p != NULL)
    {
        cout << p->data <<" ";
        p = p->next;
    }
}
int pop()  //Popping is always from top
{
    int x = -1;
    if (top == NULL)
        cout << "Stack underflow" << endl;
    else {
        Node *p = top;
        x = p->data;
        top = p->next;
        delete p;

    }
    return x;
}
int main()
{
    cout << "Creating an stack using push" << endl;
    push(1);
    push(2);
    push(5);
    push(7);
    push(9);
    cout << pop() << endl;
    DisplayS();
}