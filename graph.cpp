#include <iostream>
#include "Vertex.h"
#include "Stack.h"
#include "VisitedList.h"

using namespace std;

// main vertex list
class Graph
{
    Vertex *head;
    Vertex *tail;

public:
    Graph()
    {
        setHead(NULL);
        setTail(NULL);
    }
    void setHead(Vertex *head)
    {
        this->head = head;
    }
    void setTail(Vertex *tail)
    {
        this->tail = tail;
    }
    Vertex *getHead()
    {
        return head;
    }
    Vertex *getTail()
    {
        return tail;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    bool addVertex(int data)
    {
        Vertex *newNode = new Vertex(data);
        if (isEmpty())
        {
            setHead(newNode);
            setTail(newNode);
            return true;
        }
        else
        {
            getTail()->setNext(newNode);
            setTail(newNode);
            return true;
        }
    }
    bool addEdge(int src, int dst)
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            Vertex *currVertex = getHead();
            while (currVertex != NULL)
            {
                if (currVertex->getData() == src)
                {
                    currVertex->getEdgeList()->addEdge(dst);
                    return true;
                }

                currVertex = currVertex->getNext();
            }
            return false;
        }
    }

    void print()
    {
        Vertex *currVertex = getHead();
        while (currVertex != NULL)
        {
            cout << endl;
            cout << "edges associated with " << currVertex->getData() << " ---> ";
            EdgeNode *currNode = currVertex->getEdgeList()->getHead();
            while (currNode != NULL)
            {
                cout << currNode->getDestination() << " ";
                currNode = currNode->getNext();
            }
            currVertex = currVertex->getNext();
        }
    }

    Vertex *searchVertex(int vertex)
    {
        Vertex *currentVertex = getHead();
        while (currentVertex != NULL)
        {
            if (currentVertex->getData() == vertex)
            {
                return currentVertex;
            }
            currentVertex = currentVertex->getNext();
        }
        return NULL;
    }

    void DFS(int startingVertex)
    {
        VisitedList visitedList;

        // initially set all vertices as false in visited list
        visitedList.fillList(getHead(), &visitedList);

        Stack stack;

        Vertex *vertex = searchVertex(startingVertex);
        stack.push(vertex);

        // while (!stack.empty())
        // {
        //     int currentVertex = stack.getTop();
        //     stack.pop();

        // }
    }
};

int main()
{
    // graph is directed!
    Graph obj;

    obj.addVertex(22);
    obj.addVertex(4);
    obj.addVertex(88);
    obj.addVertex(7);
    obj.addVertex(39);
    obj.addVertex(42);
    obj.addVertex(999);
    obj.addVertex(111);

    obj.addEdge(22, 4);
    obj.addEdge(4, 88);
    obj.addEdge(4, 7);
    obj.addEdge(88, 39);
    obj.addEdge(88, 42);
    obj.addEdge(42, 7);
    obj.addEdge(111, 999);

    obj.DFS(88);

    obj.print();
}