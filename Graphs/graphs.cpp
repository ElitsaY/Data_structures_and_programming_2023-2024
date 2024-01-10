#include <iostream>
#include <vector>
#include <queue>


void dfs(int current, std::vector<bool> &visited, const std::vector<std::vector<int>> &adjList) {
    visited[current] = true;

    // Vurshim rabota
    std::cout << current << ' ';

    for (int destination : adjList[current]) {
        if (!visited[destination]) {
            dfs(destination, visited, adjList);
        }
    }
}

void bfs(int current, std::vector<bool> &visited, const std::vector<std::vector<int>> &adjList) {
    std::queue<int> q;
    q.push(current);
    visited[current] = true;

    int remaining = 1;
    int level = 0;

    while (!q.empty()) {
        current = q.front();
        q.pop();
        --remaining;

        // Vurshim rabota
        std::cout << current << " at level " << level << '\n';

        for (int destination : adjList[current]) {
            if (!visited[destination]) {
                visited[destination] = true;
                q.push(destination);
            }
        }

        if (remaining == 0) {
            ++level;
            remaining = q.size();
        }
    }
}

// Keep in mind there are multiple input formats and here we choose one but ultimately you have to be able to read another formats also
// Another example format is being given directly Adjacency list or Adjacency matrix.
// Harder input format to parse is given results from some iteration of the graph.
// Keep in mind last option will have some constraints so it produces different outputs for different graphs.

// Input format:
// V E
// u1 v1
// ...
// u_e v_e
int main() {
    int V, E;
    std::cin >> V >> E;

    std::vector<std::vector<int>> adjList(V);
    for (int i = 0; i < E; ++i) {
        int u, v;
        std::cin >> u >> v;

        adjList[u].push_back(v);
        // If undirected:
        adjList[v].push_back(u);
    }

    // Try every unvisited starting point if we don't know the graph is strongly connected for directed graphs or connected for undirected graphs
    std::vector<bool> visited(V, false);
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            std::cout << "New component\n";
            bfs(i, visited, adjList);
            std::cout << "\n";
        }
    }

    return 0;
}