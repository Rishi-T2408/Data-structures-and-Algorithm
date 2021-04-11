//Creating doubly linked list
#include <iostream>
using namespace std;

struct Node{
    Node *prev;
    int data;
    Node *next;   //It has two self referential pointer
}*first=NULL;

void CreateD(int A[],int lenght)  //Dumping an array to an doubly linked list
{
    Node *t;
    Node *last;
    t=new Node;
    t->data=A[0];
    t->next=NULL;
    t->prev=NULL;
    first=t;
    last=first;
    t=NULL;
    for(int i=1;i<lenght;i++)
    {
        t=new Node;
        t->data=A[i];
        last->next=t;
        t->prev=last;
        t->next=NULL;
        last=last->next;
    }
}

void DisplayD()
{
    Node *p;
    p=first;
    while(p!=NULL)
    {
        cout<<p->data<<"  ";
        p=p->next;
    }
    
}

int main()
{
    int A[]={2,4,5,6,7,1,9};
    int lenght=sizeof(A)/sizeof(int);
    cout<<"Creating doubly linked list"<<endl;
    
    CreateD(A,lenght);
    cout<<(first->next)->next->data<<endl;
    cout<<(first->next)->prev->data<<endl;  
    DisplayD();
    
}