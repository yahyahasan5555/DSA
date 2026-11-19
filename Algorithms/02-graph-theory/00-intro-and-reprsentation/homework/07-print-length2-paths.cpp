#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

void add_directed_edge(Graph& graph, int from, int to) {
       graph[from].push_back(to);
}

void print_paths_of_length_2(const Graph& graph) {
       for(int node {}; node < (int) graph.size(); ++node) 
              for(int neighbor: graph[node]) 
                     for(int neighbor2: graph[neighbor]) 
                            cout << node << ' ' << neighbor << ' ' << neighbor2 << endl;
}

int main() {
       int nodes, edges; cin >> nodes >> edges;
       Graph graph(nodes, vector<int>());

       for(int e {}; e < edges; ++e) {
              int from, to; cin >> from >> to;
              add_directed_edge(graph, from, to);
       }

       print_paths_of_length_2(graph);
       return 0;
}
/*

 6 9
 2 1
 2 5
 2 0
 2 3
 0 5
 1 4
 5 4
 4 3
 4 2

0 5 4
1 4 3
1 4 2
2 1 4
2 5 4
2 0 5
4 2 1
4 2 5
4 2 0
4 2 3
5 4 3
5 4 2
*/
