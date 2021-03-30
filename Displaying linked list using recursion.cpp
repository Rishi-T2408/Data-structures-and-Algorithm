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
}     //Create krte smay 

void display(struct Node *p)
{
    if (p != NULL)
    {
        cout << p->data << endl;
        display(p->next);
    }
}

int main() {
    //For creating an linked list inside main function we create an array first
    int A[] = { 3,5,7,10,15 };  //This list stored in array we will now store this in an linked list
    int n = sizeof(A) / sizeof(n);
    create(A, n);
    display(first);
    return 0;

}