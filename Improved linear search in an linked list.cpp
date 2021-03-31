#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;   //Self referential pointer
}*first=NULL;   //This first pointer I have made

void create(int A[], int n) {
    int i;  //And tranversing and storing array elements in an linked list
    Node *t,*last; //Creating an temporay ponter for creating an new nodes
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

//Simple linear search 

int Sum(struct Node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next; //For tranversing threw the linked list
    }
    return sum;
    
}


void display() {
    Node* q;
    q = first;  //q will point to the first node
    while (q != (NULL)) {
        cout << q->data << endl;
        q = q->next;
    }
}


int SumR(struct Node *p)
{
    int sum=0;
    if(p!=NULL)
    {
        return SumR(p->next)+p->data;  //This p->next will take ous to all the nodes in oour linked list
    }
    else{
        return 0;
    }
}

Node* Lsearch(Node *p,int key)
{
    while(p!=NULL) //Transversing threw linked 
    {
        if(p->data==key)
        {
            return p;
        }
        p=p->next;
    }
    return NULL; //It means unsuccesful search
}

Node* Rsearch(Node *p,int key)
{
    if(p==NULL)
    {
        return NULL;
    }
    if(p->data==key)
    {
        return p;
    }
    return Rsearch(p->next,key);
}

//Modified linear search
Node* LMsearch(Node *p,int key)
{
    Node *q=NULL;
    while(p!=NULL)
    {
        if(p->data==key)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;  //This moves the node to head if an node value is found !!!!!
        }
        q=p; //q and p same node pe hoojayenge and fhirr p aage badhh jaayega q ke
        p=p->next;
        
    }
}
int main() {
    //For creating an linked list inside main function we create an array first
    int A[] = { 1,8,14,2,3,4,60 };  //This list stored in array we will now store this in an linked list
    int n = sizeof(A) / sizeof(n);
    create(A, n);
    Node *p=LMsearch(first,4);  //If the node is found then p will be non zero
    
    if(p!=0)
    {
        cout<<"The node with value "<<p->data<<" is found"<<endl;
    }
    else{
        cout<<"unsuccesful search"<<endl;
    }
     Node *p1=LMsearch(first,2);  //If the node is found then p will be non zero
    
    if(p1!=0)
    {
        cout<<"The node with value "<<p1->data<<" is found"<<endl;
    }
    else{
        cout<<"unsuccesful search"<<endl;
    }
     
     
    display();
    return 0;

}