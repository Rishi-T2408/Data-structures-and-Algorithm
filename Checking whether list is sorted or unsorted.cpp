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

//Inserting the new node at an given position
void insert(int x, int pos)
{
    Node* p, * t;
    //Checking whether the position is valid or not
    if (pos >= 0 && pos <= count(first))   //If pos=2 means we are inserting between node 2 and node 3
    {
        if (pos == 0)  //Inserting before all nodes
        {
            t = new Node;
            t->data = x;
            t->next = first;
            first = t;
            t = NULL;
        }
        else {
            p = first;
            for (int i = 0; i < pos - 1 && (p != NULL); i++)    //Now moving p pos-1 times for creating link
            {
                p = p->next;  //In this case also p can go to NULL
            }
            if (p)
            {
                t = new Node;
                t->data = x;
                t->next = p->next;
                p->next = t;
                t = NULL;
            }
        }
    }
    else {
        cout << "Invalid Index" << endl;
    }
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
int DeleteNode(int pos)  //We should only know the position at which it should be deleted
{
    if(pos>=1 && pos<=count(first))
    {
    int x;   //Deleted value store krne ke liye
    Node *p=first;
    Node *q=NULL;
    for(int i=0;i<pos-1;i++)
    {
        q=p;
        p=p->next;
    }
    if(p==first)
    {
        first=p->next;
        x=p->data;
        delete p;
    }
    else{
        q->next=p->next;
        x=p->data;
        delete p;
    }
    return x; 
    }
    else{
        cout<<"Invalid Index"<<endl;
        return 0;
    }
}

bool CheckSort()
{
    Node *p=first;
    Node *q=NULL;
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        if(p!=NULL)
        {
        if(p->data < q->data)  //That means it is not arranging order sorted so 
        {
            return false;
        }
        }
    }
    return true;
}
int main() {
    //For creating an linked list inside main function we create an array first
    int A[]={2,3,1,5,6,7,8,9};
    int n=sizeof(A)/sizeof(int);
    create(A,n);
    display();cout<<endl;
    bool m=CheckSort();
    if(m==true)
    {
        cout<<"List is sorted!!!!!"<<endl;
    }
    else{
        cout<<"List is unsorted!!!"<<endl;
    }
    return 0;

}