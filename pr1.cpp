#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;                   // Number of vertices
    vector<vector<int>> adj; // Adjacency list representation of graph

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void display()
    {
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
    }

    // Recursive Depth First Search (DFS)
    void RecursiveDFS(int v, vector<bool> &visited, int level)
    {
        visited[v] = true;
        cout << "Visiting node " << v << " at level " << level << endl;
        for (int u : adj[v])
        {
            if (!visited[u])
            {
                RecursiveDFS(u, visited, level + 1);
            }
        }
    }

    void DFS(int v)
    {
        vector<bool> visited(V, false);
        RecursiveDFS(v, visited, 0);
    }

    // Recursive Breadth First Search (BFS)
    void RecursiveBFS(queue<pair<int, int>> &q, vector<bool> &visited)
    {
        if (q.empty())
            return;

        int u = q.front().first;
        int level = q.front().second;
        q.pop();
        cout << "Visiting node " << u << " at level " << level << endl;
        for (int w : adj[u])
        {
            if (!visited[w])
            {
                visited[w] = true;
                q.push({w, level + 1});
            }
        }
        RecursiveBFS(q, visited);
    }

    void BFS(int v)
    {
        vector<bool> visited(V, false);
        queue<pair<int, int>> q; // Queue to store vertex and its level
        q.push({v, 0});
        visited[v] = true;
        RecursiveBFS(q, visited);
    }
};

int main()
{
    int choice, v;
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    g.DFS(0);

    // g.display();

    return 0;

    do
    {
        cout << "\nMenu:\n1. BFS Traversal (Recursive)\n2. DFS Traversal (Recursive)\n3. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter starting vertex for BFS: ";
            cin >> v;
            cout << "BFS Traversal (Recursive):" << endl;
            g.BFS(v);
            break;
        case 2:
            cout << "\nEnter starting vertex for DFS: ";
            cin >> v;
            cout << "DFS Traversal (Recursive):" << endl;
            g.DFS(v);
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != 3);

    return 0;
}
