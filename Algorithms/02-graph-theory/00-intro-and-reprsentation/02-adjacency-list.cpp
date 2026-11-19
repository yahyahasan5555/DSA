#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

// graph is a vector of lists: graph[u] = all the neighbors of u. from/to are 0-based indices
void add_undirected_edge(Graph& mat, int from, int to) {
    mat[from].push_back(to);
    mat[to].push_back(from);
}

void add_directed_edge(Graph& mat, int from, int to) {
    mat[from].push_back(to);
}

void print_graph(Graph& mat, int n) {
    for(int from {}; from < n; ++from) {
        cout << "Node: " << from << " has neighbors: ";
        for(int to {}; to < (int) mat[from].size(); ++to)
            cout << mat[from][to] << ' ';
        cout << endl;
    }
}

int main() {
    int nodes, edges; cin >> nodes >> edges;

    Graph graph(nodes); // inner vectors are empty!

    for(int e {}; e < edges; ++e) {
        int from, to; cin >> from >> to;
        add_undirected_edge(graph, from, to);
    }

    print_graph(graph, nodes);
    return 0;
}

/****
sh-5.3$ g++ adjacency_list.cpp -o adjacency_list.out
sh-5.3$ ./adjacency_list.out
5 8
0 1 1 2 2 3 4 3 3 2 4 3 0 1 4 3

Node: 0 has neighbors: 1 1
Node: 1 has neighbors: 0 2 0
Node: 2 has neighbors: 1 3 3
Node: 3 has neighbors: 2 4 2 4 4
Node: 4 has neighbors: 3 3 3
*/