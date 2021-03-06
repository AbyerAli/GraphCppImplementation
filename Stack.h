
#include <iostream>
using namespace std;
#include "Vertex.h"
#pragma once


//  Stack
class StackNode
{
    int vertex;
    StackNode *next;

public:
    StackNode()
    {
        this->next = NULL;
    }
    StackNode(int vertex)
    {
        this->vertex = vertex;
        next = NULL;
    }
    int getData()
    {
        return vertex;
    }
    void setData(int vertex)
    {
        this->vertex = vertex;
    }
    void setNext(StackNode *next)
    {
        this->next = next;
    }
    StackNode *getNext()
    {
        return next;
    }
};

class Stack
{
    StackNode *head;
    StackNode *tail;

public:
    Stack() {
        setHead(NULL);
        setTail(NULL);
    }
    void setHead(StackNode *Head)
    {
        this->head = Head;
    }
    bool empty()
    {
        return head == NULL;
    }
    void setTail(StackNode *Tail)
    {
        this->tail = Tail;
    }
    StackNode *getHead()
    {
        return this->head;
    }
    StackNode *getTail()
    {
        return tail;
    }

    // return vertex in head
    int getTop()
    {
        return getHead()->getData();
    }

    // addOnHead
    void push(int vertex)
    {
        StackNode *newNode = new StackNode(vertex);
        if (empty())
        {
            setHead(newNode);
            setTail(newNode);
        }
        else
        {
            newNode->setNext(getHead());
            setHead(newNode);
        }
    }

    // removeFromHead
    void pop()
    {
        if (empty())
        {
            cout << "nothing to pop" << endl;
        }
        else
        {
            if (getHead()->getNext() == NULL)
            {
                delete getHead();
                setHead(NULL);
                setTail(NULL);
            }
            else
            {
                StackNode *rmNode = getHead();
                setHead(rmNode->getNext());
                delete rmNode;
                rmNode = NULL;
            }
        }
    }
};
//----------------------------------------------------------