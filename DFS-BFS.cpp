#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int vSize = 100;
vector<vector<int>> adjList(vSize, vector<int>());
vector<bool> visited(vSize, false);

void DFS(int vert)
{
    if (!visited[vert])
    {
        cout << vert << " ";
        visited[vert] = 1;
        for (int i = 0; i < adjList[vert].size(); i++)
        {
            if (!visited[adjList[vert][i]])
            {
                DFS(adjList[vert][i]);
            }
        }
    }
}

void BFS(int root)
{
    queue<int> Q;
    Q.push(root);
    while (!Q.empty())
    {
        int var = Q.front();
        Q.pop();
        cout << var << " ";
        visited[var] = true;
        for (int i = 0; i < adjList[var].size(); i++)
        {
            if (!visited[adjList[var][i]])
            {
                Q.push(adjList[var][i]);
                visited[adjList[var][i]] = true;
            }
        }
    }
}

int main()
{
    int vertices, edges;
    cout << "No. of vertices : ";
    cin >> vertices;
    cout << "\n No. of edges : ";
    cin >> edges;
    int x, y;
    for (int i = 1; i <= edges; i++)
    {
        cout << "Enter edge " << i << " : ";
        cin >> x >> y;
        adjList[x].push_back(y);
        // For undirected tree
        // adjList[y].push_back(x);
    }
    cout << "\n\nDFS : ";
    for (int i = 1; i <= vertices; i++)
    {
        if (!visited[i])
        DFS(i);
    }
    visited.assign(visited.size(), false);
    cout << "\n BFS : ";

    for (int i = 1; i <= vertices; i++)
    {
        if (!visited[i])
        BFS(i);
    }

    return 0;
}