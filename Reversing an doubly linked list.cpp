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

void ReverseD()
{
    Node *p=first,*temp;
    while(p!=NULL)
    {
        temp=p->next;
        p->next=p->prev;
        p->prev=temp;
        p=p->prev;
        if(p!=NULL && p->next==NULL)
        {
            first=p;
        }
        //Now I have reversed it in an general way so that the I can use older Display function
    }
}

int main()
{
    int A[]={2,4,5,6,7,1,9};
    int lenght=sizeof(A)/sizeof(int);
    cout<<"Creating doubly linked list"<<endl;
    CreateD(A,lenght);
    ReverseD();
    DisplayD();
}