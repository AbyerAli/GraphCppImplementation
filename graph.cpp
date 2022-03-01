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

        //use this, currentVertexTop from stack = top of stack here to perform operation on;
        Vertex* currVertex = searchVertex(startingVertex);
        Stack stack;

        //first add the starting vertex on stack
        stack.push(startingVertex);

        while (!stack.empty())
        {
            //check if dead end node && marked true
            if (currVertex->getEdgeList()->getHead() == NULL && visitedList.isVisited(currVertex->getData()))
            {
                stack.pop();
            }
            EdgeNode* currEdgeNode = currVertex->getEdgeList()->getHead();
            // traverse adj list using currentVertexTop & keep traversing until dead end
            while (currEdgeNode != NULL)
            {
                cout << currVertex->getData() << endl;

                // if the currentEdge is checked then hop on to the next vertex(edge)
                if (visitedList.isVisited(currEdgeNode->getDestination()))
                {
                    currEdgeNode = currEdgeNode->getNext();
                }
                // the current edge is not visited then mark it as visited and move on to the next edge as appropriate
                if (!visitedList.isVisited(currEdgeNode->getDestination()))
                {
                    // change the currentVertex to the found one using searchVertex function.
                    stack.push(currEdgeNode->getDestination());
                    visitedList.setVisited(currEdgeNode->getDestination(), true);
                    currVertex = searchVertex(currEdgeNode->getDestination());
                    currEdgeNode = currVertex->getEdgeList()->getHead();
                }
            }
        }
    }

    // void DFS(int startingVertex)
    // {
    //     VisitedList visitedList;
    //     // initially set all vertices as false in visited list
    //     visitedList.fillList(getHead(), &visitedList);

    //     Stack stack;

    //     - first add the starting vertex on stack

    //     while (!stack.empty())
    //     {

    //         if(check if dead end node && marked true) {
    //             stack.pop();
    //         }

    //         //use this
    //         currentVertexTop from stack = top of stack here to perform operation on;

    //         //keep traversing until dead end
    //         while (traverse adj list using currentVertexTop )
    //         {

    //             if( the currentEdge is checked then hop on to the next vertex (edge) ){
    //                 //do you shit here
    //             }
    //             if(the current edge is not visited then mark it as visited and move on to the next edge as appropriate) {
    //                 //change the currentVertex to the found one using searchVertex function.
    //             }
    //         }

    //     }
    // }
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
    obj.addEdge(39, 42);
    obj.addEdge(42, 7);
    // obj.addEdge(111, 999);

    obj.DFS(22);

    obj.print();
}