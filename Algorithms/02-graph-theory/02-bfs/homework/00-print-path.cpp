#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<vector<int>> Graph;

constexpr int OO = 1e9; // INF 
constexpr int START_NODE = {0};

void add_directed_edge(Graph& graph, int from, int to) {
       graph[from].push_back(to);
}      

vector<int> bfs(const Graph& graph, int start) {
       int sz {(int) graph.size()};

       vector<bool> visited(sz);
       vector<int> parent(sz, -1);
       queue<int> q;

       q.push(start);
       visited[start] = true;

       while(!q.empty()) {
              int cur {q.front()};
              q.pop();

              for(int neighbor: graph[cur]) {
                     if(!visited[neighbor]) {
                            parent[neighbor] = cur;
                            visited[neighbor] = true;
                            q.push(neighbor);
                     }
              }
       }
       return parent;
}


void print_path(int start, const vector<int>& parent) {
       if(start == -1)
              return;

       print_path(parent[start], parent);
       cout << start << ' ';
}


void test_case(void) {
       int nodes, edges; cin >> nodes >> edges;
       Graph graph(nodes); // adjacency list.

       for(int e {}; e < edges; ++e) {
              int from, to; cin >> from >> to; // nodes range: [0, nodes[
              add_directed_edge(graph, from, to);
       }

       vector<int> parent = bfs(graph, START_NODE);
       for(int node {}; node < nodes; ++node) {
              if(node == START_NODE)
                     continue;

              cout << "Path from " << START_NODE << " to " << node << ": ";
              if(parent[node] == -1)
                     cout << "Not exist";
              else print_path(node, parent);
              
              cout << '\n'; 
       }

       cout << endl;
}

int main() {
       freopen("01_BFS_path.txt", "rt", stdin);

       int tests; cin >> tests;
       while(tests--)
              test_case();

       return 0;
}
