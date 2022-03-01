#include <iostream>
using namespace std;


class EdgeNode {
    int destination;
    EdgeNode* next;
public:
    EdgeNode() {
        this->next = NULL;
    }
    EdgeNode(int destination) {
        this->destination = destination;
        this->next = NULL;
    }
    int getDestination() {
        return destination;
    }
    EdgeNode* getNext() {
        return next;
    }
    void setDestination(int destination) {
        this->destination = destination;
    }
    void setNext(EdgeNode* next) {
        this->next = next;
    }
};

class EdgeList {
    EdgeNode* head;
    EdgeNode* tail;
public:
    EdgeList() {
        setHead(NULL);
        setTail(NULL);
    }
    void setHead(EdgeNode* head) {
        this->head = head;
    }
    void setTail(EdgeNode* tail) {
        this->tail = tail;
    }
    EdgeNode* getHead() {
        return head;
    }
    EdgeNode* getTail() {
        return tail;
    }
    bool isEmpty() {
        return head == NULL;
    }
    //addOnTail
    void addEdge(int destination) {
        EdgeNode* newNode = new EdgeNode(destination);
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
    bool removeEdge(int destination) {
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
                    EdgeNode* tempNode = getHead();
                    setHead(tempNode->getNext());
                    delete tempNode;
                    tempNode = NULL;
                    return true;
                }
                
            }
            
            EdgeNode* currNode = getHead();
            while (currNode != NULL)
            {
                if (currNode->getNext()->getDestination() == destination)
                {
                    EdgeNode* tempNode = currNode->getNext();
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
    void setHead(VisitedListNode* head) {
        this->head = head;
    }
    void setTail(VisitedListNode* tail) {
        this->tail = tail;
    }
    VisitedListNode* getHead() {
        return head;
    }
    VisitedListNode* getTail() {
        return tail;
    }
    bool isEmpty() {
        return head == NULL;
    }
    void setVisited(int vertex, bool visited)
    {
        VisitedListNode *currentNode = getHead();
        while (currentNode != NULL)
        {
            if(currentNode->getVertex() == vertex)
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
            if(currentNode->getVertex() == vertex)
            {
                return currentNode->getVisited();
            }
            currentNode = currentNode->getNext();
        }
    }
    void addVertexData(int vertex, bool isVisited)
    {
        VisitedListNode *newNode = new VisitedListNode(vertex, isVisited);
        if(isEmpty())
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
};

//----------------------------------------------------------


class Vertex {
    int data;
    Vertex* next;
    EdgeList edgeList;
public:
    Vertex() {
        this->next = NULL;
    }
    Vertex(int data) {
        this->data = data;
        this->next = NULL;
    }
    void setData(int data) {
        this->data = data;
    }
    void setNext(Vertex* next) {
        this->next = next;
    }
    int getData() {
        return data;
    }
    Vertex* getNext() {
        return next;
    }
    EdgeList* getEdgeList() {
        return &edgeList;
    }
};


//main vertex list
class Graph {
    Vertex* head;
    Vertex* tail;
    VisitedList visitedList;
public:
    Graph() {
        setHead(NULL);
        setTail(NULL);
    }
    void setHead(Vertex* head) {
        this->head = head;
    }
    void setTail(Vertex* tail) {
        this->tail = tail;
    }
    Vertex* getHead() {
        return head;
    }
    Vertex* getTail() {
        return tail;
    }
    bool isEmpty() {
        return head == NULL;
    }
    bool addVertex(int data) {
        Vertex* newNode = new Vertex(data);
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
    bool addEdge(int src, int dst) {
        if (isEmpty())
        {
            return false;
        }
        else 
        {
            Vertex* currVertex = getHead();
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

    void print() {
        Vertex* currVertex = getHead();
        while (currVertex != NULL)
        {
            cout << endl;
            cout << "edges associated with " << currVertex->getData() << " ---> ";
            EdgeNode* currNode = currVertex->getEdgeList()->getHead();
            while (currNode != NULL)
            {
                cout << currNode->getDestination() << " " ;
                currNode = currNode->getNext();
            }
            currVertex = currVertex->getNext();
        }
        
    }
};




int main() {
    //graph is directed!
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





    obj.print();
}