#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef vector<vector<int>> Graph;

void add_directed_edge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

// Depth-limited DFS: is `target` reachable from `node` using AT MOST `limit` edges?
// best_depth[v] = the smallest depth at which v was reached in THIS iteration.
// We go into v again only if we reach it with a smaller depth (a plain visited array
// could block the shorter path that is needed under the depth limit).
bool dfs(const Graph& graph, int node, int target, int depth, int limit, vector<int>& best_depth) {
    if(node == target)
        return true;

    if(depth == limit) // don't go deeper than the limit
        return false;

    for(int neighbor: graph[node]) {
        if(best_depth[neighbor] > depth + 1) {
            best_depth[neighbor] = depth + 1;
            if(dfs(graph, neighbor, target, depth + 1, limit, best_depth))
                return true;
        }
    }
    return false;
}

// Iterative deepening: run the depth-limited DFS with limit = 0, 1, 2, ... until the target is found.
// Returns the minimum number of edges from source to target (-1 if not reachable within max_depth).
int iddfs(const Graph& graph, int source, int target, int max_depth) {
    int n {(int) graph.size()};

    for(int limit {}; limit <= max_depth; ++limit) {
        vector<int> best_depth(n, INT_MAX); // reset for every new limit
        best_depth[source] = 0;

        if(dfs(graph, source, target, 0, limit, best_depth))
            return limit; // the first limit that works is the shortest path (in edges)
    }
    return -1;
}

int main() {
    int nodes, edges; cin >> nodes >> edges;

    Graph graph(nodes);
    for(int e {}; e < edges; ++e) {
        int from, to; cin >> from >> to;
        add_directed_edge(graph, from, to);
    }

    int source, target; cin >> source >> target;
    int ans {iddfs(graph, source, target, nodes - 1)}; // a shortest path never has more than V - 1 edges

    if(ans == -1)
        cout << "Node " << target << " is NOT reachable from node " << source << endl;
    else
        cout << "Shortest path from " << source << " to " << target << " has " << ans << " edges" << endl;

    return 0;
}

/*
sh-5.3$ g++ 01-iddfs.cpp -o a.out
sh-5.3$ ./a.out
6 7
0 1
1 2
2 3
0 4
4 3
3 5
2 5
0 5

Shortest path from 0 to 5 has 3 edges
*/