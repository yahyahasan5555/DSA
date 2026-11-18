#include <iostream>
#include <vector>
#include <unordered_set>

// Suppose Unweighted Graph
// 0-based --> from 0 to (n.of nodes - 1)

using namespace std;
using Graph = vector<unordered_set<int>>;

// Both pushing functions are O(1) time and space complexity.
void add_directed_edge(Graph& adj, int from, int to) {
       adj[from].insert(to);
}

void add_undirected_edge(Graph& adj, int from, int to) { 
       adj[from].insert(to);
       adj[to].insert(from);
}

// O(V + E) time and O(1) extra space
void print_graph(Graph& adj) {
       for(int vertex {}; vertex < (int) adj.size(); ++vertex) {
              cout << "Vertex: " << vertex << " has neighbors: ";
              
              for(const int& neighbor: adj[vertex]) 
                     cout << neighbor << ' ';
              
              cout << endl;
       }
}

int main() {
       int nodes, edges; cin >> nodes >> edges;

       Graph graph(nodes); 

       for(int e {}; e < edges; ++e) {
              int from, to; cin >> from >> to;
              add_undirected_edge(graph, from, to);
       }

       print_graph(graph);
       return 0;
}

/*
 * Advantages:
       - We can iterate on the neighbors in O(degree), while can check from the edge in O(1) ONLY.
 *
 * Disadvantages:  
       - Now our graph doesn't supports multiple edges (Impractical, and we may do workarounds)
       - Hash tables extra memory
       - like any hash table, needs more caution for dealing with the LF (load factor).
 * 
 * Time complexity:
       - O(1) for add, remove and check edge.
       - O(Degree) for iterate on node's neighbors.        
 *
 * Space complexity:
       - O(E + V) for represent the graph.
 */