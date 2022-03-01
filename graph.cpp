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

    void DFS()
    {
        VisitedList visitedList;
        // initially set all vertices as false in visited list
        visitedList.fillList(getHead());

        Vertex *currentVertex = getHead();
        while (currentVertex != NULL)
        {
            
            Stack stack;
            stack.push(currentVertex->getData());
            while (!stack.empty())
            {
                int top = stack.getTop();
                stack.pop();

                Vertex *v = searchVertex(top);
                if(!visitedList.isVisited(v->getData()))
                {
                    cout << top << endl;
                    visitedList.setVisited(top, true);
                }
                EdgeNode *edgeNode = v->getEdgeList()->getHead();
                while (edgeNode != NULL)
                {
                    if(!visitedList.isVisited(edgeNode->getDestination())) {
                        stack.push(edgeNode->getDestination());
                    } 
                    edgeNode = edgeNode->getNext();
                }
            }
            
            currentVertex = currentVertex->getNext();
        }
        
    }
};

int main()
{
    // graph is directed!
    Graph obj;
    // case - 1
    // obj.addVertex(22);
    // obj.addVertex(4);
    // obj.addVertex(88);
    // obj.addVertex(7);
    // obj.addVertex(39);
    // obj.addVertex(42);
    // obj.addVertex(999);
    // obj.addVertex(111);

    // obj.addEdge(22, 4);
    // obj.addEdge(4, 88);
    // obj.addEdge(4, 7);
    // obj.addEdge(88, 39);
    // obj.addEdge(88, 42);
    // obj.addEdge(39, 42);
    // obj.addEdge(42, 7);

    // case - 2
    // obj.addVertex(1);
    // obj.addVertex(4);
    // obj.addVertex(8);
    // obj.addVertex(9);
    // obj.addVertex(10);
    // obj.addVertex(12);
    // obj.addVertex(15);
    // obj.addVertex(44);
    // obj.addVertex(55);
    // obj.addVertex(67);

    // obj.addEdge(1, 8);
    // obj.addEdge(8, 10);
    // obj.addEdge(8, 9);
    // obj.addEdge(10, 4);
    // obj.addEdge(10, 12);
    // obj.addEdge(9, 44);
    // obj.addEdge(9, 55);
    // obj.addEdge(12, 4);
    // obj.addEdge(4, 15);
    // obj.addEdge(12, 67);
    // obj.addEdge(67, 44);
    // obj.addEdge(44, 55);
    obj.addVertex(1);
    obj.addVertex(2);
    obj.addVertex(3);
    obj.addVertex(4);
    obj.addVertex(6);


    obj.addEdge(1, 6);
    obj.addEdge(2, 6);
    obj.addEdge(3, 6);
    obj.addEdge(4, 6);

    obj.DFS();

    // obj.print();
}