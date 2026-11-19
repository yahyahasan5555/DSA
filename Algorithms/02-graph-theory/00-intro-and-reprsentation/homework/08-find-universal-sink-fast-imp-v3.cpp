#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Adjacency matrix - directed graph - including multi-edges and loops.
using Graph = vector<vector<int>>;

void add_directed_edge(Graph& graph, int from, int to) {
       graph[from][to] += 1;
}

// O(n) time, O(1) extra space
bool is_universal_sink(const Graph& graph, int sink) {
       int sz {(int) graph.size()};
       for(int j {}; j < sz; ++j) {
              // the sink node doesn't link to any other node, including itself (self loop).
              if(graph[sink][j])
                     return false;

              // each other node should link to the sink node (except the sink itself).
              if(sink != j && !graph[j][sink])
                     return false;
       } return true;
}

// O(N) Time  ONLYYYYYYYYY
int find_universal_sink_fast(const Graph& graph) {
       int i {}, j {}, sz {(int) graph.size()};
       while(i < sz && j < sz) {
              if(i == j) {
                     if(graph[i][j])
                            i = j = j + 1;
                     else 
                            ++j;
                     
                     continue;
              }

              // ELSE:
              if(!graph[i][j]) {
                     if(graph[j][i])
                            ++j;
                     else 
                            i = j = j + 1;
              } else 
                     i = j;
       }

       if(i < sz && is_universal_sink(graph, i))
              return i;
       return -1;
}

void test_case(void) {
       int nodes, edges; cin >> nodes >> edges;
       Graph graph(nodes, vector<int>(nodes));

       for(int e {}; e < edges; ++e) {
              int from, to; cin >> from >> to;
              add_directed_edge(graph, from, to);
       }

       cout << find_universal_sink_fast(graph) << endl;
}

int main() {
       freopen("find_sink-input.txt", "rt", stdin);
       int t; cin >> t;
       while(t--) test_case();
       return 0;
}

