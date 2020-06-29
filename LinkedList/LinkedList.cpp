#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    int getSize() { return size; }

    void append(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void printList()
    {
        Node *currentNode = head;
        if (!currentNode)
        {
            cout << "List is empty" << endl;
        }
        else
        {
            while (currentNode)
            {
                cout << currentNode->data << " ";
                currentNode = currentNode->next;
            }
            cout << endl;
        }
    }

    void prepend(int val)
    {
        Node *temp = head;
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head = newNode;
            newNode->next = temp;
        }
        size++;
    }

    void deleteNode()
    {
        Node *temp = head;
        if (!head)
        {
            cout << "List is empty" << endl;
        }
        head = head->next;
        delete temp;
    }

    void deleteLastNode()
    {
        Node *previousNode = NULL, *currentNode = head;
        if (!currentNode)
        {
            cout << "List is empty" << endl;
            return;
        }
        while (currentNode->next)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        tail = previousNode;
        previousNode->next = NULL;
        delete currentNode;
    }

    void remoteAtPosition(int pos)
    {
        Node *previousNode = NULL;
        Node *currentNode = head;
        if (pos < 1 || pos > size)
        {
            cout << "Invalid postion" << endl;
            return;
        }
        if (pos == 1)
        {
            deleteNode();
            return;
        }
        if (pos == size)
        {
            deleteLastNode();
            return;
        }
        for (int i = 1; i < pos; i++)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        previousNode->next = currentNode->next;
        delete currentNode;
    }

    void insertAtPostion(int pos, int val)
    {
        Node *previousNode = NULL;
        Node *currentNode = head;
        Node *newNode;
        if (pos < 1 || pos > size + 1)
        {
            cout << "Invalid postion" << endl;
            return;
        }
        if (pos == 1)
        {
            prepend(val);
            return;
        }
        if (pos == size + 1 || pos == size)
        {
            append(val);
            return;
        }
        newNode = new Node(val);
        for (int i = 1; i < pos; i++)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
};

int main()
{
    LinkedList *list = new LinkedList();
    list->append(10);
    list->append(12);
    list->append(13);
    list->append(14);
    list->prepend(9);
    list->prepend(8);
    list->prepend(7);
    list->prepend(6);
    list->printList();
    list->deleteNode();
    list->deleteNode();
    list->printList();
    list->deleteLastNode();
    list->printList();
    list->remoteAtPosition(3);
    list->printList();
    list->remoteAtPosition(10);
    list->insertAtPostion(1, 7);
    list->insertAtPostion(5, 14);
    list->insertAtPostion(3, 10);
    list->printList();
    return 0;
}