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
int CountD()
{
    Node *p=first;
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    return count;
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

void InsertD(int pos,int x)
{
    if(pos>=0 && pos<=CountD())
    {
    Node *p,*q;
    Node *t=new Node;
    t->data=x;
    p=first;
    if(pos==0)
    {
        if(first==NULL)
        {
            first=t;
            t->next=NULL;
            t->prev=NULL;
        }
        else{
            t->next=first;
            first->prev=t;
            first=t;
            first->prev=NULL;
        }
    }
    else{
        for(int i=0;i<(pos-1);i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=t;
        t->prev=p;
        t->next=q;
        if(q!=NULL)
        q->prev=t;
    }
    }
    else{
        cout<<"Invalid position"<<endl;
    }
}

int main()
{
    int A[]={10,20,30,40,50};
    int lenght = sizeof(A)/sizeof(int);
    CreateD(A,lenght);
    cout<<"Creating doubly linked list"<<endl;
    InsertD(0,25);

    DisplayD();
  
    cout<<endl;
    return 0;
}