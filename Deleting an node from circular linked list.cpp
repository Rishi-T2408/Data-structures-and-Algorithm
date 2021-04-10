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
    if(Head!=NULL)
    {
    Node *p=Head;
    do{
        cout<<p->data<<"  ";
        p=p->next;
    }while(p!=Head);
    }
    else{
        cout<<"Nothing to show"<<endl;
    }
}

int lenght()
{
    Node *p=Head;
    int count=0;
    do{
        count++;
        p=p->next;
    }
    while(p!=Head);
    return count;
}

int DeleteC(int pos)
{
    Node *p,*q;
    int x;
    if(pos>=1 && pos<=lenght())
    {
    if(pos==1)
    {
        p=Head;
        x=Head->data;
        while(p->next!=Head)
        p=p->next;
        if(p==Head)
        {
            delete Head;
            Head=NULL;
        }
        else{
            p->next=Head->next;
            delete Head;
            Head=p->next;
        }
    }
    else{
        p=Head;
        for(int i=0;i<(pos-2);i++)
        {
            p=p->next;
        }
        q=p->next;
        x=q->data;
        p->next=q->next;
        delete q;
    }
    return x;
    }
    else{
        return -300;
    }
}

int main() {
    //For creating an linked list inside main function we create an array first
    int A[] = { 2,3,4,5,6};  //This list stored in array we will now store this in an linked list
    int n = sizeof(A) / sizeof(n);
    createC(A, n);  //So this will create circular linked list
    displayC();
    cout<<endl;
    int x=DeleteC(10);
    if(x==-300)
    {
        cout<<"Invalid position"<<endl;
    }
    else{
    cout<<"Value deleted is "<<x<<endl;
    displayC();
    }
    return 0;
}