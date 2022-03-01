#include <iostream>
#pragma once
using namespace std;

class EdgeNode
{
    int destination;
    EdgeNode *next;

public:
    EdgeNode()
    {
        this->next = NULL;
    }
    EdgeNode(int destination)
    {
        this->destination = destination;
        this->next = NULL;
    }
    int getDestination()
    {
        return destination;
    }
    EdgeNode *getNext()
    {
        return next;
    }
    void setDestination(int destination)
    {
        this->destination = destination;
    }
    void setNext(EdgeNode *next)
    {
        this->next = next;
    }
};

class EdgeList
{
    EdgeNode *head;
    EdgeNode *tail;

public:
    EdgeList()
    {
        setHead(NULL);
        setTail(NULL);
    }
    void setHead(EdgeNode *head)
    {
        this->head = head;
    }
    void setTail(EdgeNode *tail)
    {
        this->tail = tail;
    }
    EdgeNode *getHead()
    {
        return head;
    }
    EdgeNode *getTail()
    {
        return tail;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    // addOnTail
    void addEdge(int destination)
    {
        EdgeNode *newNode = new EdgeNode(destination);
        if (isEmpty())
        {
            setHead(newNode);
            setTail(newNode);
        }
        else
        {
            getTail()->setNext(newNode);
            setTail(newNode);
        }
    }
    bool removeEdge(int destination)
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            if (getHead()->getDestination() == destination)
            {

                if (getHead() == getTail())
                {
                    delete getHead();
                    setHead(NULL);
                    setTail(NULL);
                    return true;
                }
                else
                {
                    EdgeNode *tempNode = getHead();
                    setHead(tempNode->getNext());
                    delete tempNode;
                    tempNode = NULL;
                    return true;
                }
            }

            EdgeNode *currNode = getHead();
            while (currNode != NULL)
            {
                if (currNode->getNext()->getDestination() == destination)
                {
                    EdgeNode *tempNode = currNode->getNext();
                    currNode->setNext(tempNode->getNext());
                    delete tempNode;
                    tempNode = NULL;
                    return true;
                }

                currNode = currNode->getNext();
            }
            return false;
        }
    }
};