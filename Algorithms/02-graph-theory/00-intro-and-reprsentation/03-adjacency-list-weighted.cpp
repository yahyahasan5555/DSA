#include <iostream>
#include <vector>

using namespace std;

struct edge {
    int to;
    int cost;
};

using Graph = vector<vector<edge>>;

// graph is a vector of lists: graph[u] = all the edges that leave u (to + cost). from/to are 0-based indices
void add_undirected_edge(Graph& mat, int from, int to, int cost) {
    mat[from].push_back({to, cost});
    mat[to].push_back({from, cost});
}

void add_directed_edge(Graph& mat, int from, int to, int cost) {
    mat[from].push_back({to, cost});
}

void print_graph(Graph& mat, int n) {
    for(int from {}; from < n; ++from) {
        cout << "Node: " << from << " has edges: ";
        for(int to {}; to < (int) mat[from].size(); ++to)
            cout << "(To " << mat[from][to].to << ", Cost " << mat[from][to].cost << ") ";
        cout << endl;
    }
}

int main() {
    int nodes, edges; cin >> nodes >> edges;

    Graph graph(nodes); // inner vectors are empty!

    for(int e {}; e < edges; ++e) {
        int from, to, cost; cin >> from >> to >> cost;
        add_undirected_edge(graph, from, to, cost);
    }

    print_graph(graph, nodes);
    return 0;
}

/****
sh-5.3$ g++ adjacency_list_weighted.cpp -o adjacency_list_weighted.out
sh-5.3$ ./adjacency_list_weighted.out
4 4
0 1 10
1 2 5
2 3 7
3 0 20

Node: 0 has edges: (To 1, Cost 10) (To 3, Cost 20)
Node: 1 has edges: (To 0, Cost 10) (To 2, Cost 5)
Node: 2 has edges: (To 1, Cost 5) (To 3, Cost 7)
Node: 3 has edges: (To 2, Cost 7) (To 0, Cost 20)
*/