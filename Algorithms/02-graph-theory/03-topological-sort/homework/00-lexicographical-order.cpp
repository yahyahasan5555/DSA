#include <iostream>
#include <vector>
#include <queue>

/*
The only change, replace the queue with priority queue that picks the smallest first
This way we pick always the smallest one among all current valid choices
 */

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

void add_directed_edge(Graph& graph, int from, int to) {
       graph[from].push_back(to);
}

// Kahn's algorithm:
vector<int> topological_sort(const Graph& graph) { // O( E+V )
       int sz {(int) graph.size()};

       // compute in-degrees
       vector<int> in_degree(sz);
       for(const auto& vec: graph)
              for(int node: vec)
                     ++in_degree[node];

       // add the current nodes with in-degree 0 (start points)
       // can I use -1 trick with the pq, but will need to update the whole code
       priority_queue<int, vector<int>, greater<int>> ready; 
       for(int node {}; node < sz; ++node)
              if(!in_degree[node])
                     ready.push(node);

       vector<int> ordering; // result.
       while(!ready.empty()) {
              int cur {ready.top()};
              ready.pop();

              ordering.push_back(cur);
              for(int neighbor: graph[cur])
                     if(in_degree[neighbor]) // greater than 0
                            if(!--in_degree[neighbor])
                                   ready.push(neighbor);
       }
                            
       // should be the result array size = the actually size
       // otherwise there is a cycle.
       if(ordering.size() != sz)
              ordering.clear(); // or throw an error
       return ordering;
}

void test_case(void) {
       int nodes, edges; cin >> nodes >> edges;
       Graph graph(nodes);

       for (int e = 0; e < edges; ++e) {
              int from, to;
              cin >> from >> to;
              add_directed_edge(graph, from, to);
       }

       vector<int> ordering = topological_sort(graph);

       if (ordering.empty())
              cout << "There is a cycle\n";
       else {
              for (int node : ordering)
                     cout << node << " ";
              cout << "\n";
       }

}

int main() {
       int cases; cin >> cases;
       while(cases--)
              test_case();

       return 0;
}

