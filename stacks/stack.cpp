// Stack implementation in c++

#include <iostream>
using namespace std;

int top = -1;

//check if stack is empty or not
bool isEmpty()
{
    return top == -1;
}

// check if stack is full or not
bool isFull(int size)
{
    return top == size - 1;
}

// function that pushes the element into the element
void push(int stack[], int element, int size)
{
    if (isFull(size))
        cout << "Stack overflow" << endl;
    else
        stack[++top] = element;
}

// function that pop outs a=last element from the stack
void pop(int stack[])
{
    if (isEmpty())
        cout << "Stack underflow" << endl;
    else
        top--;
}

// function that return the top most element
int getTop(int stack[])
{
    return stack[top];
}

// function that returns the size of the stack
int getSize(int stack[])
{
    return top + 1;
}

void printStack(int stack[])
{
    for (int i = top; i >= 0; i--)
        cout << stack[i] << endl;
    cout << "End of list" << endl;
}

// main function
int main()
{
    int Stack_size = 10;
    int Stack[Stack_size];
    push(Stack, 10, Stack_size);
    push(Stack, 11, Stack_size);
    push(Stack, 12, Stack_size);
    push(Stack, 13, Stack_size);
    push(Stack, 14, Stack_size);
    printStack(Stack);
    pop(Stack);
    pop(Stack);
    printStack(Stack);
    cout << "Top of stack is " << getTop(Stack) << endl;
    cout << "Size of the stack is " << getSize(Stack) << endl;
    return 0;
}
