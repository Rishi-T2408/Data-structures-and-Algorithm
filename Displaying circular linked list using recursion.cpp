// Creating and displaying an linked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;   //Self referential pointer
}*first=NULL,*Head=NULL;   //This first pointer I have made

void createC(int A[], int n) {
    int i;  
    Node *t,*last; 
    //Creating first node
    first = new Node;
    first->data = A[0];
    first->next = NULL; //Pointing first node no where
    last = first; //Tjere is only one node now 
      

    //Now with the help of for loop we will creare new nodes
    for (int i = 1; i < n; i++)  //Now we will link the nodes
    {
        t = new Node; //We will create new nodes using t
        t->data = A[i];
        last->next = t;
        last = t;  //In this way last is linking the nodes and t is creating new one
    }
    last->next=first;  //This will create circular linked list
    Head=first;
    first=NULL;
    
}

void displayC()
{
    Node *p=Head;
    do{
        cout<<p->data<<"  ";
        p=p->next;
    }while(p!=Head);
}

void displayCR(Node *p)
{
    
    //As flag should be declared only once so we used static int
    static int flag=0;  //The head and the iterative pointer p has met one time
    if(p!=Head || flag==0)
    {
        cout<<p->data<<"  ";
        p=p->next;
        if(p==Head)
        {
            flag++;
        }
        displayCR(p);
    }
}

int main() {
    //For creating an linked list inside main function we create an array first
    int A[] = { 1,5,7,8,9,15};  //This list stored in array we will now store this in an linked list
    int n = sizeof(A) / sizeof(n);
    createC(A, n);  //So this will create circular linked list
    displayCR(Head);
    return 0;

}