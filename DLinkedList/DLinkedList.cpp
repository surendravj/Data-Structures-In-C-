#include <iostream>

using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

class DLinkedList
{
public:
    Node *head;
    int size;
    Node *tail;
    DLinkedList()
    {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    int getSize()
    {
        return size;
    }
    void prepend(int data)
    {
        Node *newNode = new Node(data);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void append(int data)
    {
        Node *temp = head, *newNode;
        newNode = new Node(data);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            tail = newNode;
        }
        size++;
    }

    void insert(int data, int pos)
    {
        Node *currentNode = head, *newNode = new Node(data);
        if (pos < 1 || pos > size + 1)
            return;
        if (pos == 1)
            prepend(data);
        if (pos == size + 1)
            append(data);
        else
        {
            for (int i = 1; i < pos; i++)
                currentNode = currentNode->next;
            currentNode->prev->next = newNode;
            newNode->prev = currentNode->prev;
            newNode->next = currentNode;
            currentNode->prev = newNode;
            size++;
        }
    }

    void removeAtHead()
    {
        if (!head){
            cout << "List is empty" << endl;
            return;
        }
        if (!head->next)
        {
            delete head;
            head = NULL;
            tail = NULL;
            size--;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
            size--;
        }
    }

    void removeAtTail()
    {
        if (!head)
            cout << "List is empty" << endl;
        if (!head->next)
        {
            removeAtHead();
            head = NULL;
            tail = NULL;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = NULL;
            size--;
        }
    }

    void remove(int pos)
    {
        Node *currentNode = head;
        if (!head){
            cout << "List is empty" << endl;
            return;
        }
    
        if (pos < 1 || pos > size){
            cout << "Invalid index position" << endl;
            return;
        }
        if (pos == 1)
        {
            removeAtHead();
            return;
        }
        if (pos == size)
        {
            removeAtTail();
            return;
        }
        else
        {
            for (int i = 1; i < pos; i++)
                currentNode = currentNode->next;
            currentNode->prev->next = currentNode->next;
            currentNode->next->prev = currentNode->prev;
            delete currentNode;
            size--;
        }
    }

    void print()
    {
        Node *temp = head;
        if (!head)
        {
            cout << "List is empty" << endl;
        }
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void printReverse()
    {
        Node *temp = tail;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main()
{
    DLinkedList *list = new DLinkedList();
    list->prepend(10);
    list->prepend(5);
    list->prepend(1);
    list->print();
    list->append(11);
    list->append(12);
    list->append(13);
    list->print();
    list->insert(2, 2);
    list->insert(3, 3);
    list->insert(4, 4);
    list->print();
    list->printReverse();
    list->removeAtHead();
    list->removeAtHead();
    list->print();
    list->removeAtTail();
    list->removeAtTail();
    list->print();
    list->remove(1);
    list->remove(4);
    list->remove(2);
    list->print();
    return 0;
}