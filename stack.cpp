//Stack and Queue Using Array And Linked List
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next = NULL;
        data = -1;
    }
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
class Stack
{
    Node *head;
    int sz;

public:
    Stack()
    {
        head = NULL;
        sz = 0;
    }
    void push(int d)
    {
        // insert at front
        Node *n = new Node(d);
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            n->next = head;
            head = n;
        }
        sz++;
    }
    void pop()
    {
        // remove from front
        if (head == NULL)
            return;
        if (head->next == NULL)
        {
            head = NULL;
        }
        else
        {
            Node *thead = head->next;
            head->next = NULL;
            head = thead;
        }
        sz--;
    }
    int top()
    {
        if (head == NULL)
            return -1;
        else
        {
            return head->data;
        }
    }
    int getSize()
    {
        return sz;
    }
    bool isEmpty()
    {
        return sz == 0;
    }
};
class StackII
{
    int *arr;
    int sz;
    int tos;
public:
    StackII()
    {
        arr = new int[10000000];
        sz = 0;
        tos = -1;
    }
    void push(int d)
    {
        // insert at front
        tos++;
        arr[tos] = d;
        sz++;
    }
    void pop()
    {
        // remove from front
        if(tos==-1){
            return;
        }
        else{
            tos--;
        }
        sz--;
    }
    int top()
    {
        if(tos == -1){
            return -1;
        }
        else{
            return arr[tos];
        }
    }
    int getSize()
    {
        return sz;
    }
    bool isEmpty()
    {
        return sz == 0;
    }
};
class Queue
{
    Node *head;
    Node* tail;
    int sz;

public:
    Queue()
    {
        head = tail = NULL;
        sz = 0;
    }
    void push(int d)
    {
        // insert at back
        Node *n = new Node(d);
        if (head == NULL)
        {
            head = tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
        sz++;
    }
    void pop()
    {
        // remove from front
        if (head == NULL)
            return;
        if (head->next == NULL)
        {
            head = tail = NULL;
        }
        else
        {
            Node *thead = head->next;
            head->next = NULL;
            head = thead;
        }
        sz--;
    }
    int front()
    {
        if (head == NULL)
            return -1;
        else
        {
            return head->data;
        }
    }
    int getSize()
    {
        return sz;
    }
    bool isEmpty()
    {
        return sz == 0;
    }
};
class QueueII
{
    int *arr;
    int front;
    int back;
    int sz;
    int cap;

public:
    QueueII()
    {
        arr = new int[10000000];
        front = back = -1;
        sz = 0;
        cap = 10000000;
    }
    QueueII(int cap){
        arr = new int[cap];
        front = back = -1;
        sz = 0;
        this->cap = cap;
    }
    void push(int d)
    {
        // insert at back
        if(back+1==cap){
            cout << "Queue Overflow" << endl;
            return;
        }

        if (front == -1)
        {
            front++,back++;
            arr[front] = d;
        }
        else
        {
            back++;
            arr[back] = d;
        }
        sz++;
    }
    void pop()
    {
        // remove from front
        if(front==-1){
            cout << "Queue Underflow" << endl;
            return;
        }
        if (front == back)
        {
            front = back = -1;
        }
        else{
            front++;
        }
        sz--;
    }
    int aage()
    {
        if(front==-1){
            return -1;
        }
        else
        {
            return arr[front];
        }
    }
    int getSize()
    {
        return sz;
    }
    bool isEmpty()
    {
        return sz == 0;
    }
};
int main()
{
    QueueII s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    while(!s.isEmpty()){
        cout << s.aage() << endl;
        s.pop();
    }

}