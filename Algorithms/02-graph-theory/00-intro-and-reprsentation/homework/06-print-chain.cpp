#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

// the graph here is a simple rooted tree.
void add_directed_edge(Graph& graph, int from, int to) {
       graph[from].push_back(to);
}

void print_chain(const Graph& graph, vector<bool>& visited, int start) {
       if(visited[start])
              return;

       cout << start << ' ';
       if(graph[start].empty()) return;
              
       visited[start] = true;
       print_chain(graph, visited, graph[start][0]);
       visited[start] = false;
}

int main() {
       int nodes, edges; cin >> nodes >> edges;
       Graph graph(nodes, vector<int>());

       for(int e {}; e < edges; ++e) {
              int from, to; cin >> from >> to;
              add_directed_edge(graph, from, to);
       }

       int queries; cin >> queries;
       vector<bool> visited(nodes);
       while(queries--) {
              int start_node; cin >> start_node;

              print_chain(graph, visited, start_node);
              cout << endl;
       }
       return 0;
}

/*
g++ 06-print-chain.cpp -o chain.out
./chain.out
3 3
0 1
1 2
2 1
3
1
       1 2 
2
       2 1 
0
       0 1 2 

       
./chain.out
6 5
4 1
1 2
5 3
0 5
3 4
4
0
       0 5 3 4 1 2
3
       3 4 1 2
1
       1 2
2
       2
*/