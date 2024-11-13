#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V);
    void addEdge(int u, int v);
    bool isSafe(int v, vector<int> &color, int c);
    bool graphColoringUtil(int m, vector<int> &color, int v);
    void graphColoring(int m);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // Since the graph is undirected
}

bool Graph::isSafe(int v, vector<int> &color, int c) {
    for (int i : adj[v]) {
        if (color[i] == c) {
            return false;
        }
    }
    return true;
}

bool Graph::graphColoringUtil(int m, vector<int> &color, int v) {
    if (v == V) {
        return true; // All vertices are assigned a color
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, color, c)) {
            color[v] = c; // Assign color c to vertex v

            if (graphColoringUtil(m, color, v + 1)) {
                return true;
            }

            color[v] = 0; // Backtrack
        }
    }
    return false;
}

void Graph::graphColoring(int m) {
    vector<int> color(V, 0); // Initialize all vertices as uncolored

    if (graphColoringUtil(m, color, 0)) {
        cout << "Solution exists: Following are the assigned colors:\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " ---> Color " << color[i] << endl;
        }
    } else {
        cout << "Solution does not exist\n";
    }
}

int main() {
    int V = 4; // Number of vertices
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    
    int m = 3; // Number of colors
    g.graphColoring(m);

    return 0;
}

