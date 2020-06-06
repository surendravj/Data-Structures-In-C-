#include <iostream>

using namespace std;

#define SIZE 1000

class Queue
{
public:
    int Q[SIZE];
    int front;
    int rear;
    Queue()
    {
        front = rear = -1;
    }

    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        return false;
    }

    bool isFull()
    {
        return rear == SIZE - 1;
    }

    void Enqueue(int val)
    {
        if (isFull())
            cout << "Queue overflow" << endl;
        else
        {
            if (front == -1)
            {
                front++;
            }
            Q[++rear] = val;
        }
    }

    void Dequeue()
    {
        if (isEmpty())
            cout << "Queue underflow" << endl;
        else
        {
            if (front == rear)
                front = rear = -1;
            else
                front++;
        }
    }

    void peek()
    {
        if (isEmpty())
            cout << "Queue underflow" << endl;
        else
            cout << Q[front] << endl;
    }

    void display()
    {
        if (rear == -1 && front == -1)
            cout << "Queue is empty" << endl;
        else
            for (int i = front; i <= rear; i++)
                cout << Q[i] << endl;
    }
};

//Main function

int main()
{
    Queue q;
    q.Enqueue(12);
    q.Enqueue(13);
    q.Enqueue(14);
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
}

// 12 13 14
// F      R