// Queue implementation using Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct Queue
{
    int rear;
    int front;
    int size;
    int* Q;   //This will make an array that will behave as Queue b behaving in FIFO principle
};

void enqueue(Queue* q, int x)
{
    if (q->rear != (q->size - 1))
    {
        q->rear++;
        q->Q[q->rear] = x;  //Value enqueued
    }
    else {
        cout << "Queue overflow" << endl;
    }
}

int dequeue(Queue* q)
{
    int x = -1;  //If we are not able to deque then it will return -1
    if (q->front != q->rear)
    {
        q->front++;
        x = q->Q[q->front];  //Deleted as queue starts from f+1 to r
    }
    else {
        cout << "Queue underflow" << endl;
    }
    return x;
}
void Display(Queue q)
{
    if (q.front == q.rear)
        cout << "Queue is empty" << endl;
    else {
        for (int i = q.front + 1; i <= q.rear; i++)
            cout << q.Q[i] << "  ";
    }

}
int main()
{
    Queue q;
    q.front = -1;
    q.rear = -1;
    cout << "Enter size of the queue" << endl;
    cin >> q.size;
    q.Q = new int[q.size];  //Empty queue created
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    
    dequeue(&q);  //As 5 is inserted first so 5 will be deleted
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    
    Display(q);
    enqueue(&q, 15);
    return 0;
    
}
