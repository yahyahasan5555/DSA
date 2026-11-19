#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

// graph is a 2d matrix. from/to are 0-based indices.
// mat[from][to] = the COST of the edge (not the number of edges). 0 = no edge (OK only if every cost > 0).
void add_undirected_edge(Graph& mat, int from, int to, int cost) {
    mat[from][to] = cost;
    mat[to][from] = cost;
}

void add_directed_edge(Graph& mat, int from, int to, int cost) {
    mat[from][to] = cost;
}

void print_graph(Graph& mat, int n) {
    for(int from {}; from < n; ++from)
        for(int to {}; to < n; ++to)
            if(mat[from][to])
                cout << "From " << from << ", To " << to << ", With cost " << mat[from][to] << endl;
}

int main() {
    int nodes, edges; cin >> nodes >> edges;

    Graph graph(nodes, vector<int>(nodes));

    for(int e {}; e < edges; ++e) {
        int from, to, cost; cin >> from >> to >> cost;
        add_undirected_edge(graph, from, to, cost);
    }

    print_graph(graph, nodes);
    return 0;
}

/****
sh-5.3$ g++ adjacency_matrix_weighted.cpp -o adjacency_matrix_weighted.out
sh-5.3$ ./adjacency_matrix_weighted.out
4 4
0 1 10
1 2 5
2 3 7
3 0 20

From 0, To 1, With cost 10
From 0, To 3, With cost 20
From 1, To 0, With cost 10
From 1, To 2, With cost 5
From 2, To 1, With cost 5
From 2, To 3, With cost 7
From 3, To 0, With cost 20
From 3, To 2, With cost 7
*/