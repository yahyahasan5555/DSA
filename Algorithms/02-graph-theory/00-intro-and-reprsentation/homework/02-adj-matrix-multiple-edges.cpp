// !NOTE ADJACENCY MATRIX NOT ADJACENCY LIST

#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<vector<int>>>;

void add_undirected_edge(Graph& mat, int from, int to, int weight) {
       mat[from][to].push_back(weight);
       mat[to][from].push_back(weight);
}

void add_directed_edge(Graph& mat, int from, int to, int weight) {
       mat[from][to].push_back(weight);
}

// Time O(V^2 + E)
void print_graph(Graph& graph) {
       int sz {(int) graph.size()};

       for(int from {}; from < sz; ++from) 
              for(int to {}; to < sz; ++to) 
                     for(int weight {}; weight < (int) graph[from][to].size(); ++weight)
                            cout << "From " << from << " to " << to << " the cost is " << graph[from][to][weight] << '\n';
}

// O(V^2 + E) time and O(V^2 + E) extra space
int main() {
       int nodes, edges; cin >> nodes >> edges;
       Graph graph(nodes, vector<vector<int>>(nodes, vector<int>()));

       for(int e {}; e < edges; ++e) {
              int from, to, weight; cin >> from >> to >> weight;
              add_directed_edge(graph, from, to, weight);
       }

       print_graph(graph);
       return 0;
}

/* OUTPUT:

sh-5.3$ g++ 02-adj-matrix-multiple-edges.cpp -o out
sh-5.3$ ./out
5 10
0 1 10
1 2 7
0 1 7
2 3 9
2 3 15
3 4 50
0 4 52
0 4 30
2 4 36
4 0 150
From 0 to 1 the cost is 10
From 0 to 1 the cost is 7
From 0 to 4 the cost is 52
From 0 to 4 the cost is 30
From 1 to 2 the cost is 7
From 2 to 3 the cost is 9
From 2 to 3 the cost is 15
From 2 to 4 the cost is 36
From 3 to 4 the cost is 50
From 4 to 0 the cost is 150

 * complexity:
       - O(V^2 + E) for printing
       - O(V^2 + E) extra space
       - O(V + E) iterate over node's neighbors
       - O(1) check wether an edge exists or not!
       - O(1) add edge
*/