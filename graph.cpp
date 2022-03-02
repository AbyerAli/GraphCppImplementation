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

        // visit every Vertex from vertexList and perform DFS on each vertex;
        // Graph maybe disconnected so DFS on every vertex
        while (currentVertex != NULL)
        {
            //instantiate stack for current Vertex and push it on the stack 
            Stack stack;
            stack.push(currentVertex->getData());
            
            // traverse all the vertices associated with the currentVertex
            // pop the top of stack before that save the top "v"
            while (!stack.empty())
            {
                int top = stack.getTop();
                stack.pop();

                Vertex *v = searchVertex(top);
                //if the poped vertex is not visited then add it to the visited list.
                if(!visitedList.isVisited(v->getData()))
                {
                    cout << top << endl;
                    visitedList.setVisited(top, true);
                }
                
                // now traverse each vertix associated with the current Vertex and push them to the stack if not present in the visited list
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
 
    obj.addVertex(2);
    obj.addVertex(34);
    obj.addVertex(29);
    obj.addVertex(1);
    obj.addVertex(39);
    obj.addVertex(50);



    obj.addEdge(2, 34);
    obj.addEdge(34, 2);

    obj.addEdge(34, 29);
    obj.addEdge(29, 34);

    obj.addEdge(34, 1);
    obj.addEdge(1, 34);

    obj.addEdge(29, 50);
    obj.addEdge(50, 29);

    obj.addEdge(1, 39);
    obj.addEdge(39, 1);

    obj.addEdge(39, 50);
    obj.addEdge(50, 39);



    obj.DFS();

    // obj.print();
}