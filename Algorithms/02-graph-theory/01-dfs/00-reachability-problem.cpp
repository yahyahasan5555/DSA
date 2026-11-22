#include<iostream>
#include<vector>

using namespace std;

typedef vector<vector<int>> Graph;

void add_directed_edge(Graph &graph, int from, int to) {
    graph[from].push_back(to);
}

void dfs(int node, const Graph& graph, vector<bool>& visited) {
    visited[node] = true;

    for(int neighbor: graph[node]) {
        if(!visited[neighbor]) {
            cout << "We can reach: " << neighbor << '\n';
            dfs(neighbor, graph, visited);
        }
    }
}

void print_reachability(const Graph& graph) {
    int sz {(int) graph.size()};

    for(int node {}; node < sz; ++node) {
        cout << "Reachable set of node " << node << " is:\n";
        vector<bool> vis(sz); // Reset
        dfs(node, graph, vis);
    }
}

int main() {
    int nodes, edges; cin >> nodes >> edges;

    Graph graph(nodes);
    for(int e {}; e < edges; ++e) {
        int from, to; cin >> from >> to;
        add_directed_edge(graph, from, to);
    }

    print_reachability(graph);
    return 0;
}

/*
Complexity
- One dfs() call:               time O(V + E), every node is visited once and every edge is checked once.
- print_reachability (V calls): time O(V * (V + E)).
- Memory (auxiliary):           O(V) = the visited array (V) + the recursion stack (at most V calls, O(1) each).
  The graph itself (adjacency list) takes O(V + E), but it is the input, so it isn't counted as auxiliary.

NOTE: the start node itself is not printed (it is marked visited first), even when it is on a cycle.

sh-5.3$ g++ 00-reachability-problem.cpp -o a.out
sh-5.3$ ./a.out
7 9
2 0
0 1
0 3
1 4
1 0
4 3
3 1
5 6
6 6

Reachable set of node 0 is:
We can reach: 1
We can reach: 4
We can reach: 3
Reachable set of node 1 is:
We can reach: 4
We can reach: 3
We can reach: 0
Reachable set of node 2 is:
We can reach: 0
We can reach: 1
We can reach: 4
We can reach: 3
Reachable set of node 3 is:
We can reach: 1
We can reach: 4
We can reach: 0
Reachable set of node 4 is:
We can reach: 3
We can reach: 1
We can reach: 0
Reachable set of node 5 is:
We can reach: 6
Reachable set of node 6 is:
*/