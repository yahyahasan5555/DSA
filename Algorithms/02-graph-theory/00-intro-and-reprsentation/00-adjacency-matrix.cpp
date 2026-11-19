#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

// graph is a 2d matrix. from/to are 0-based indices
void add_undirected_edge(Graph& mat, int from, int to) {
    mat[from][to] += 1;
    mat[to][from] += 1;
}

void add_directed_edge(Graph& mat, int from, int to) {
    mat[from][to] += 1;
}

void print_graph(Graph& mat, int n) {
    for(int from {}; from < n; ++from)
        for(int to {}; to < n; ++to)
            if(mat[from][to])
                cout << "From " << from << ", To " << to << ", There are " << mat[from][to] << " edges" << endl;
}

int main() {
    int nodes, edges; cin >> nodes >> edges;

    Graph graph(nodes, vector<int>(nodes));

    for(int e {}; e < edges; ++e) {
        int from, to; cin >> from >> to;
        add_undirected_edge(graph, from, to);
    }

    print_graph(graph, nodes);
    return 0;
}

/****
sh-5.3$ g++ adjacency_matrix.cpp -o adjacency_matrix.out
sh-5.3$ ./adjacency_matrix.out
5 8
0 1
1 2
2 3
4 3
3 2
4 3
0 1
4 3

From 0, To 1, There are 2 edges
From 1, To 0, There are 2 edges
From 1, To 2, There are 1 edges
From 2, To 1, There are 1 edges
From 2, To 3, There are 2 edges
From 3, To 2, There are 2 edges
From 3, To 4, There are 3 edges
From 4, To 3, There are 3 edges
*/