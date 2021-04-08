#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node* next;   //Self referential pointer
}*first = NULL,*second=NULL,*third=NULL,*last=NULL;   //This first pointer I have made

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


void create2(int A[], int n) {
    int i;  //And tranversing and storing array elements in an linked list
    Node* t, * last; //Creating an temporay ponter for creating an new nodes
    //last will help to point the last node and create new nodes from the last

    //Creating first node
    second = new Node;
    second->data = A[0];
    second->next = NULL; //Pointing first node no where
    last = second; //Tjere is only one node now 


    //Now with the help of for loop we will creare new nodes
    for (int i = 1; i < n; i++)  //Now we will link the nodes
    {
        t = new Node; //We will create new nodes using t
        t->data = A[i];
        last->next = t;
        last = t;  //In this way last is linking the nodes and t is creating new one
    }
    
    
}



void display(Node *q) {
    
    while (q != (NULL)) {
        cout << q->data << "  ";
        q = q->next;
    }
}
void merge(Node *f,Node *s)
{
    if (f->data < s->data)  //This is the special case where we wanna point third to first node of merge linked list
    {
        third = f;
        last = f;
        f = f->next;
        third->next = NULL;
    }
    else {
        third = s;
        last = s;
        s = s->next;
        third->next = NULL;
    }

    while (f != NULL && s != NULL)
    {
        if (f->data < s->data)
        {
            last->next = f;
            last = last->next;
            f = f->next;
            last->next = NULL;
        }
        else {
            last->next = s;
            last = last->next;
            s = s->next;
            last->next = NULL;
        }
    }
    if (f == NULL)
    {
        last->next = s;
        s = NULL;
    }
    else {
        last->next = f;
        f = NULL;   //So I have merged two linked list now
    }

    cout << "Merging two linked list.." << endl;
    display(third);
}

int main() {
    //For creating an linked list inside main function we create an array first
    int A[] = { 3,5,7,9,13 };  //This list stored in array we will now store this in an linked list
    int n = sizeof(A) / sizeof(int);
    create(A, n);
  
    int B[]={1,2,4,8,16};
    int m=sizeof(B)/sizeof(int);
    create2(B,m);
    
    //So now merging the two linked list
    merge(first,second);
    
    return 0;

}
