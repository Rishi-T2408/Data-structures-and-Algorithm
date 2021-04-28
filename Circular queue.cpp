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
    if (((q->rear+1)%(q->size)) != (q->front))   //Now it will go on in circular fashion by following the mod trend
    {
        q->rear = ((q->rear + 1) % (q->size));
        q->Q[q->rear] = x;  //Value enqueued
    }
    else {
        cout << "Circular Queue is full" << endl;
    }
}

int dequeue(Queue* q)
{
    int x = -1;  //If we are not able to deque then it will return -1
    if (q->front != q->rear)
    {
        q->front = ((q->front + 1) % (q->size));
        x = q->Q[q->front];  //Deleted as queue starts from f+1 to r
    }
    else {
        cout << "Circular Queue is empty" << endl;
    }
    return x;
}
void Display(Queue q)
{
    if (q.front == q.rear)
        cout << "Circular Queue is empty" << endl;
    else {
        int i = q.front;
        while (i != q.rear)
        {
            i = (i + 1) % (q.size);
            cout << q.Q[i] << "  ";
        }

    }
    

}
int main()
{
    Queue q;
    //As now it is an circular queue so We will start front and rear from 0 (array starting)
    q.front = 0;
    q.rear = 0;
    cout << "Enter size of the circular queue" << endl;
    cin >> q.size;
    q.Q = new int[q.size];  //Empty queue created
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    Display(q);  //First we filled all the things
    dequeue(&q);  //Then emptied
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    Display(q);
    return 0;

}
