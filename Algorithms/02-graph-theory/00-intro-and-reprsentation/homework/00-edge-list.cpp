#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
       int from;
       int to;
       int cost;

       Edge(int from, int to, int cost): from(from), to(to), cost(cost) {}
       
       bool operator<(const Edge& other) const {
              return cost < other.cost;
       }

       void print() const {
              cout << "Edge: (" << from << ", " << to << ", " << cost << ")\n";
       }
};

using Graph = vector<Edge>;

// O(1) Time and Space complexity.
void add_edge(Graph& graph, int from, int to, int cost) {
       graph.push_back(Edge(from, to, cost));
}

// O(E) time, O(1) extra space
void print_adj_matrix(Graph& graph) {
       for(const Edge& e: graph) 
              e.print();       
}

// O(E log E) Time (for sorting), O(E) extra space.
int main() {
       int edges; cin >> edges;
       Graph graph;

       for(int e {}; e < edges; ++e) {
              int from, to, cost; cin >> from >> to >> cost;
              add_edge(graph, from, to, cost);
       }

       sort(graph.begin(), graph.end());
       print_adj_matrix(graph);
       return 0;
}

/*
sh-5.3$ g++ 00-edge-list.cpp -o edge-list.out
sh-5.3$ ./edge-list.out 
5
1 2 20
1 3 21
1 4 15
5 4 16
2 4 18
Edge: (1, 4, 15)
Edge: (5, 4, 16)
Edge: (2, 4, 18)
Edge: (1, 2, 20)
Edge: (1, 3, 21)
*/
