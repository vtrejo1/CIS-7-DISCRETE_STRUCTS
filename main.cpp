#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

typedef struct {
    int vertexA;
    int vertexB;
} edge;

int *getVertexDegrees(vector<edge*> *edges);

void printHighestDegree(vector<edge*>* edges);
void printIsolatedVertices(vector<edge*>* edges);
void printNumberOfLoops(vector<edge*>* edges);
void printGraph(vector<edge*>* edges);

// Checks for a path between two vertices
bool isConnected(vector<edge*>* edges, vector<edge*>* checkedEdges, int vertex1, int vertex2);

bool isGraphConnected(vector<edge*>* edges);
bool isGraphComplete(vector<edge*>* edges);

static int vertexCount = 0;

int main()
{
    vector<edge*> *edges = new vector<edge*>;

    bool running = true;

    cout << "Commands:"     << endl;
    cout << "Add (V)ertex"  << endl;
    cout << "Add (E)dge"    << endl;
    cout << "(P)rint Graph" << endl;
    cout << "E(x)it"        << endl;

    string command;

    while(running)
    {
        cin >> command;

        if(command.compare("V") == 0)
        {
            vertexCount++;
            cout << "New vertex (ID: " << vertexCount-1 << ") created!" << endl;
        }
        else if(command.compare("E") == 0)
        {
            if(vertexCount == 0)
            {
                cout << "You must create at least one vertex first." << endl;
                continue;
            }

            cout << "Enter two vertex IDs:" << endl;

            int vertexA, vertexB;

            cin >> vertexA;
            cin >> vertexB;

            if((vertexA < 0 || vertexA > vertexCount-1) ||
                    (vertexB < 0 || vertexB > vertexCount-1))
            {
                cout << "Invalid input: vertices must be in range [0," << vertexCount-1 << "]" << endl;
                continue;
            }

            edge *newEdge = new edge;

            newEdge->vertexA = vertexA;
            newEdge->vertexB = vertexB;

            cout << "New Edge (" << vertexA << " -> " << vertexB << ") created!" << endl;

            edges->push_back(newEdge);
        }
        else if(command.compare("P") == 0)
        {
            printGraph(edges);
        }
        else if(command.compare("x") == 0)
        {
            running = false;
        }
    }
    delete[] edges;
    return 0;
}

int *getVertexDegrees(vector<edge*> *edges)
{
    int *degrees = new int[vertexCount]();

    for(unsigned int i = 0; i < edges->size(); i++)
    {
        edge *e = (*edges)[i];

        degrees[e->vertexA]++;
        degrees[e->vertexB]++;
    }

    return degrees;
}

void printHighestDegree(vector<edge*>* edges)
{
    int *degrees = getVertexDegrees(edges);
    int highest = 0;
    int highestIdx = -1;

    for(int i = 0; i < vertexCount; i++)
    {
        if(degrees[i] > highest)
        {
            highest = degrees[i];
            highestIdx = i;
        }
    }

    cout << "Vertex " << highestIdx << " has highest degree (Degree of " << highest << ")" << endl;

    delete[] degrees;
}

void printIsolatedVertices(vector<edge*> *edges)
{
    int *degrees = getVertexDegrees(edges);

    cout << "Isolated Vertices: ";

    for(int i = 0; i < vertexCount; i++)
    {
        if(degrees[i] == 0)
        {
            cout << i << " ";
        }
    }

    cout << endl;

    delete[] degrees;
}

void printNumberOfLoops(vector<edge*> *edges)
{
    int numberOfLoops = 0;

    for(int i = 0; i < edges->size(); i++)
    {
        edge *e = (*edges)[i];

        if(e->vertexA == e->vertexB)
            numberOfLoops++;
    }

    cout << "Number of loops: " << numberOfLoops << endl;
}

bool isConnected(vector<edge*> *edges, vector<edge*> *checkedEdges, int vertex1, int vertex2)
{
    bool connected = false;

    //cout << "Checking " << vertex1 << "->" << vertex2 << endl;

    for(int i = 0; i < edges->size(); i++)
    {
        edge *e = (*edges)[i];

        if((e->vertexA == vertex1 && e->vertexB == vertex2) ||
                (e->vertexB == vertex1 && e->vertexA == vertex2))
        {
            return true;
        }

        //Determine if edge has already been checked.
        if(find(checkedEdges->begin(), checkedEdges->end(), e) != checkedEdges->end())
        {
            continue;
        }
        else if(e->vertexA == vertex1)
        {
            checkedEdges->push_back(e);
            connected = isConnected(edges, checkedEdges, e->vertexB, vertex2);

            if(connected) return true;
        }
        else if(e->vertexB == vertex1)
        {
            checkedEdges->push_back(e);
            connected = isConnected(edges, checkedEdges, e->vertexA, vertex2);

            if(connected) return true;
        }
    }

    return connected;
}

bool isGraphConnected(vector<edge*> *edges)
{
    vector<edge*> *checkedEdges = new vector<edge*>();

    for(int i = 0; i < vertexCount; i++)
    {
        for(int j = 0; j < vertexCount; j++)
        {
            if(i >= j) continue;

            if(!isConnected(edges, checkedEdges, i, j))
            {
                //cout << i << " and " << j << " is not connected" << endl;
                return false;
            }

            checkedEdges->clear();
        }
    }

    delete checkedEdges;

    return true;
}

bool isGraphComplete(vector<edge*> *edges)
{
    for(int i = 0; i < vertexCount; i++)
    {
        int *connected = new int[vertexCount]();

        for(int k = 0; k < edges->size(); k++)
        {
            edge *e = (*edges)[k];

            if(e->vertexA == i)
            {
                connected[e->vertexB] = 1;
            }
            else if(e->vertexB == i)
            {
                connected[e->vertexA] = 1;
            }
        }

        for(int connIdx = 0; connIdx < vertexCount; connIdx++)
        {
            //cout << connected[connIdx] << " ";

            //All elements of connected[] should be equal to 1 (optional at connected[i])
            if(connIdx == i) continue;

            if(connected[connIdx] == 0)
                return false;
        }

        delete[] connected;
    }

    return true;
}

void printGraph(vector<edge*> *edges)
{
    printHighestDegree(edges);
    printIsolatedVertices(edges);
    printNumberOfLoops(edges);

    cout << "Graph is connected: " << isGraphConnected(edges) << endl;
    cout << "Graph is complete:  " << isGraphComplete(edges)  << endl;
}
