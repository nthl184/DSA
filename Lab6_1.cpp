/*
MSSV: 22520772
Full name: Nguyen Thi Huyen Linh
Lab6 - Homework - Exercise 1
*/

#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    int numVertices;
    vector<vector<int>> adjacencyList;
    vector<vector<int>> adjacencyMatrix;

public:
    Graph() : numVertices(0) {}

    void addVertices(int &num)
    {
        numVertices = num;
        adjacencyList.resize(num);
        adjacencyMatrix.resize(num, vector<int>(num, 0));
    }

    void addEdge(int u, int v)
    {
        if (u >= numVertices || v >= numVertices)
        {
            cout << "Error: Vertex does not exist.\n";
            return;
        }
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
        adjacencyMatrix[u][v] = 1;
        adjacencyMatrix[v][u] = 1;
    }

    void displayAdjList()
    {
        cout << "Adjacency List:\n";
        for (int i = 0; i < adjacencyList.size(); i++)
        {
            cout << i << ": ";
            for (int neighbor : adjacencyList[i])
            {
                cout << neighbor << " ";
            }
            cout << "\n";
        }
    }

    void displayAdjMatrix()
    {
        cout << "Adjacency Matrix:\n";
        for (auto &row : adjacencyMatrix)
        {
            for (int val : row)
            {
                cout << val << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    Graph graph;
    int choice;

    while (true)
    {
        cout << "Menu:\n";
        cout << "1. Add Vertices\n";
        cout << "2. Add Edge\n";
        cout << "3. Display Adjacency List\n";
        cout << "4. Display Adjacency Matrix\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout<< "Enter number of vertices: ";
            int num;
            cin>>num;
            graph.addVertices(num);
            cout << "New vertices has been added.\n";
        }
        else if (choice == 2)
        {
            cout << "Enter the number of edges: ";
            int num;
            cin>>num;
            while(num--)
            {
                int u, v;
                cout << "Enter starting vertice (u): ";
                cin >> u;
                cout << "Enter ending vertice (v): ";
                cin >> v;
                graph.addEdge(u, v);
            }
        }
        else if (choice == 3)
        {
            graph.displayAdjList();
        }
        else if (choice == 4)
        {
            graph.displayAdjMatrix();
        }
        else if (choice == 5)
        {
            cout << "Exiting the program.\n";
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
        cout<<'\n';
    }
    return 0;
}
