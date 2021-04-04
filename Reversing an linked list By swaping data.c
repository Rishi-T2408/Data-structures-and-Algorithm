#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;   //Self referential pointer
}*first = NULL;   //This first pointer I have made

void create(int A[], int n) {
    int i;  //And tranversing and storing array elements in an linked list
    Node* t, * last; //Creating an temporay ponter for creating an new nodes
    //last will help to point the last node and create new nodes from the last

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
}

void display() {
    Node* q;
    q = first;  //q will point to the first node
    while (q != (NULL)) {
        cout << q->data << "  ";
        q = q->next;
    }
}

int count(struct Node* p)
{
    int c = 0;
    while (p != NULL)  //It will take iteration till we reach end node
    {
        c++;
        p = p->next;  //So in next iteration it will point to next node
    }
    return c;
}
void InsertSort(int x)
{
    Node *p=first;
    Node *q=NULL;
    Node *t=NULL;
    while(p!=NULL)
    {
        if(p->data<x)
        {
            q=p;
            p=p->next;
        }
        else{
            break;
        }
    }
    if(p==first)
    {
        t=new Node;
        t->data=x;
        t->next=first;
        first=t;
    }
    else{
    t=new Node;
    t->data=x;
    t->next=q->next;
    q->next=t;
    }
}
void ReverseListE()
{
    Node *p=first;
    int i=0;
    int *A;
    int size=count(first);
    A= new int[size];
    while(p!=NULL)
    {
        A[i++]=p->data;
        p=p->next;

    }
    p=first;
    for(i=size-1;i>=0;i--)
    {
        p->data=A[i];
        p=p->next;
    }
}
int main() {
    //For creating an linked list inside main function we create an array first
    InsertSort(1);
    InsertSort(20);
    InsertSort(9);
    InsertSort(6);
    //Reversing the lised list by reversring the link nodes data
    cout<<"Originally it was like "<<endl;
    display();
    cout<<endl;
    cout<<"Now reversing the linked list"<<endl;
    ReverseListE();
    cout<<endl;
    display();
    return 0;

}