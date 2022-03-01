#include "EdgeList.h"
#pragma once

class Vertex
{
    int data;
    Vertex *next;
    EdgeList edgeList;

public:
    Vertex()
    {
        this->next = NULL;
    }
    Vertex(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    void setData(int data)
    {
        this->data = data;
    }
    void setNext(Vertex *next)
    {
        this->next = next;
    }
    int getData()
    {
        return data;
    }
    Vertex *getNext()
    {
        return next;
    }
    EdgeList *getEdgeList()
    {
        return &edgeList;
    }
};


