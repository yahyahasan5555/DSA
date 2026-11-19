#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Adjacency matrix - directed graph - including multi-edges and loops.
using Graph = vector<vector<int>>;

void add_directed_edge(Graph& graph, int from, int to) {
       graph[from][to] += 1;
}

// O(n^2) time, O(n) space
int find_universal_sink(const Graph& graph) {
       int sz {(int) graph.size()};
       vector<int> in_degree(sz);
       vector<bool> out_degree(sz);

       for(int from {}; from < sz; ++from) {
              for(int to {}; to < sz; ++to) {
                     if(graph[from][to]) {
                            out_degree[from] = true;
                            ++in_degree[to];
                     }
              }
       }

       for(int i {}; i < sz; ++i) {
              if(!out_degree[i] && in_degree[i] == sz - 1)
                     return i;
       } return -1;
}

void test_case(void) {
       int nodes, edges; cin >> nodes >> edges;
       Graph graph(nodes, vector<int>(nodes));

       for(int e {}; e < edges; ++e) {
              int from, to; cin >> from >> to;
              add_directed_edge(graph, from, to);
       }

       cout << find_universal_sink(graph) << endl;
}

int main() {
       int t; cin >> t;
       while(t--) test_case();
       return 0;
}

