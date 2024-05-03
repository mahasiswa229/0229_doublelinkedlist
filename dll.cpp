#include <iostream>
#include <string>
using namespace std;

struct Node 
{
    int noMhs;
    string name;
    Node* next;
    Node* prev;
};

Node* START = NULL;

void addNode()
{
    Node* newNode = new Node();
    cout << "\nEnter the roll number of the student : ";
    cin >>newNode->noMhs;
    cout << "Enter the name of the student : ";
    cin >> newNode-> name;
    
    if (START == NULL || newNode->noMhs <= START -> noMhs)
{
    if (START == NULL || newNode->noMhs <= START -> noMhs)
    {
        cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
        return;
    }
    
    newNode->next = START;
    if(START != NULL)
    {
        START->prev = newNode;
    }
    newNode->prev = NULL;
    START = newNode;
}
    else
{
    Node *current = START;
    Node *previous = START;

    while(current != NULL && current->noMhs < newNode->noMhs)
    {
        previous = current;
        current = current->next;
    }
    if(current != NULL)
    {
        current->prev = newNode;
    }

    if(previous != NULL)
    {
        previous->next = newNode;
    }
    else
    {
        START = newNode;
    }
}
};

bool search(int rollNo, Node **previous, Node **current)
{
    *previous = NULL;
    *current = START;
    while(*current != NULL && (*current)->noMhs != rollNo)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current != NULL);
}

void deleteNode()
{
    Node *previous, *current;
    int rollNo;
    cout << "\nEnter the roll number of the student whose record is to be deleted: ";
    cin >> rollNo;

    if(START = NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    current = START;
    previous = NULL;

    while(current != NULL && current->noMhs != rollNo)
    {
        previous = current;
        current = current->next;
    }

    if(current == NULL)
    {
        cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
        return;
    }

    if(current == START)
    {
        START = START->next;
        if(START != NULL)
        {
            START->prev = NULL;
        }
    }
    else
    {
        previous->next = current->next;
        if(current->next != NULL)
        {
            current->next->prev = previous;
        }
    }
    delete current;
    cout << "\x1b[32mRecord with roll number" << rollNo << "deleted\x1b[0m" endl;
}

void traverse()
{
    if(listEmpty())
    cout << "\nList is empty." << endl;
    else
    {
        cout << "\nRecord in ascending order of roll are:\n" << endl;
        Node *currentNode = START;
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << "" << currentNode->nama <<endl;
            currentNode = currentNode->next;
        }
    }
}

void revtraverse()
{
    if(listEmpty())
    cout << "\nList is empty." << endl;
    else
    {
        cout << "\nRecord in ascending order of roll are:\n" << endl;
        Node *currentNode = START;
        while (currentNode->next != NULL)
            currentNode = currentNode->next;
        while (currentNode != NULL)
        {
            cout << currentNode->noMhs << "" << currentNode->nama <<endl;
            currentNode = currentNode->prev;
        }
    }
}

void searchData()
{
    if(listempty() == true)
    {
        cout << "\nList is empty." << endl;
    }
    Node *prev, *curr;
    prev = curr = NULL;
    cout << "\nEnter the roll number of the student whose record is to be search: "
    int num;
    cin >> num;
    if(search(num, &prev, &curr) == false)
    cout << "\nRecord not found" << endl;
    else
    {
        cout << "\nRecord found" << endl;
        cout << "\nRoll number: " << curr->noMhs << endl;
        cout << "\nName: " << curr->nama << endl;
    }
}
int main()
{}