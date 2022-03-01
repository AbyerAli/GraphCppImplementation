#include "Vertex.h"
#pragma once

//--------------- Visited List----------------
class VisitedListNode
{
    int vertex;
    bool visited;
    VisitedListNode *next;

public:
    VisitedListNode()
    {
        next = NULL;
    }
    VisitedListNode(int vertex, bool visited)
    {
        next = NULL;
        this->visited = visited;
    }
    bool getVisited()
    {
        return this->visited;
    }
    void setVisited(bool visited)
    {
        this->visited = visited;
    }
    void setNext(VisitedListNode *next)
    {
        this->next = next;
    }
    VisitedListNode *getNext()
    {
        return this->next;
    }
    int getVertex()
    {
        return this->vertex;
    }
    void setVertex(int vertex)
    {
        this->vertex = vertex;
    }
};

class VisitedList
{
    VisitedListNode *head;
    VisitedListNode *tail;

public:
    VisitedList()
    {
        setHead(NULL);
        setTail(NULL);
    }
    void setHead(VisitedListNode *head)
    {
        this->head = head;
    }
    void setTail(VisitedListNode *tail)
    {
        this->tail = tail;
    }
    VisitedListNode *getHead()
    {
        return head;
    }
    VisitedListNode *getTail()
    {
        return tail;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    void setVisited(int vertex, bool visited)
    {
        VisitedListNode *currentNode = getHead();
        while (currentNode != NULL)
        {
            if (currentNode->getVertex() == vertex)
            {
                currentNode->setVisited(true);
                return;
            }
            currentNode = currentNode->getNext();
        }
    }
    bool isVisited(int vertex)
    {
        VisitedListNode *currentNode = getHead();
        while (currentNode != NULL)
        {
            if (currentNode->getVertex() == vertex)
            {
                return currentNode->getVisited();
            }
            currentNode = currentNode->getNext();
        }
    }
    void addVertexData(int vertex, bool isVisited)
    {
        VisitedListNode *newNode = new VisitedListNode(vertex, isVisited);
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
    void fillList(Vertex *vertexListHead, VisitedList *visitedList)
    {
        Vertex *currentVertexNode = vertexListHead;
        while (currentVertexNode != NULL)
        {
            // basically addOnTail
            visitedList->addVertexData(currentVertexNode->getData(), false);
            currentVertexNode = currentVertexNode->getNext();
        }
    }
};