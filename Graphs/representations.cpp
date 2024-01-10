#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// Number of vertices
int V;

// Representations:

// Adjacency list
std::vector<std::vector<int>> adjList(V);

// Adjacency matrix.
// Has the benefit of constant time lookup if there is an edge between given vertices u and v
std::vector<std::vector<bool>> adjMatrix(V, std::vector<bool>(V, false));
// if adjMatrix[u][v] == true it means there is directed edge from u to v

// All the above assume your vertices are integer from 0, ..., V-1
// If this is not the case use unordered_map to convert from given data to integer (index them manually)
// Let's say we have city names (string) as vertices
std::unordered_map<std::string, int> toIndex;
std::unordered_map<int, std::string> toName;
// The idea to use those is when reading input if you see UNSEEN till now vertex (unseen city name in this case) to assign it the next free index (you start at 0 and increment it)
// if (toIndex.count(cityName) == 0) {
    // toIndex[cityName] = nextFree;
    // toName[nextFree] = cityName;
    // ++nextFree;
// }

// Another thing to consider is weighted graphs:
// Adjacency list:
template <class T>
struct Edge {
    int destination;
    T weight;
};
// Example with weight being int
std::vector<std::vector<Edge<int>>> weightedAdjList;

// Adjacency matrix:
template <class T>
struct EdgeWeight {
    T* weight;

    EdgeWeight() : weight(nullptr) {

    }

    EdgeWeight(const T &weight) {
        this->weight = new T(weight);
    }

    ~EdgeWeight() {
        delete weight;
    }

    operator bool() const {
        return weight != nullptr;
    }

    EdgeWeight(const EdgeWeight &) = delete;
    EdgeWeight& operator= (const EdgeWeight &) = delete;
};
// Example with weight being int
std::vector<std::vector<EdgeWeight<int>>> weightedAdjMatrix(V, std::vector<EdgeWeight<int>>(V, 0));

// Note you don't need as complex of a structure and you can just add another adjMatrix for the weights:
// std::vector<std::vector<bool>> adjMatrix(V, std::vector<bool>(V, false));
// std::vector<std::vector<int>> weightedAdjMatrix(V, std::vector<int>(V, 0)); // Again used int as example type for weight
// You use the adjMatrix to check if there is edge between vertices and if so you can look up the weight in the weightedAdjMatrix


// Most versatile approach!
// Using maps and sets only. For example I will use string as vertex type:
// This approach has all the good properties of the above representations (asymptotically). Downside is it has a lot of MEMORY OVERHEAD.
// 1. It has near the same iteration speed (iterating neighbours) like adjLists (asymptotically all approaches have same time complexity O(V) but we talk in practice)
// 2. It has near the same look up for edge between given vertices like adjMatrix (asymptotically equal O(1))
// Unweighted:
std::unordered_map<std::string, std::unordered_set<std::string>> unweightedAdj;
// Weighted (for example using double as weight):
std::unordered_map<std::string, std::unordered_map<std::string, double>> weightedAdj;


// NOTE: all these representations above have directed edges but what happens if you have undirected graph?
// Answer: just add two edges: one from u to v, and another one from v to u


// List of edges and list of vertices. Used in this algorithm for example: https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm
// As the name suggests we keep a list of edges and list of vertices:
// std::vector<Vertex<T>> vertices;
// std::vector<Edge<T>> edgeList;


// Last approach (last we talk about but keep in mind there are more graph representations we won't talk about)
// Use everything you have learned in Discrete Math and OOP and make clases for:
// Graph - it is container similar to Binary tree but Vertex can have != 2 children
// Vertex (contains: possibly some data, a list of children pointers or some Edge like struct if it is weighted graph)



// The choice of representation is based of the needs of your algorithm. Choose wisely!
// The algorithm itself depends on the problem you are solving. Good questions to ask yourself when choosing algorithm are:
// Is the graph acyclic?
// Is it directed?
// Is it weighted?
// Does it have negative weight edges?
// Does it have negative weight cycles?