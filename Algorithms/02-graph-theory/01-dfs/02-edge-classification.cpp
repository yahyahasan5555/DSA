#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> GRAPH;

void add_directed_edge(GRAPH &graph, int from, int to) {
	graph[from].push_back(to);
}

void dfs(GRAPH &graph, int node, vector<int> &started, vector<int> &finished, int &time) {
	started[node] = time++;

	for (int neighbour : graph[node]) {
		if (started[neighbour] == -1) { // tree edge
			cout << "Tree Edge: " << node << " " << neighbour << "\n";
			dfs(graph, neighbour, started, finished, time);
		} else {	// 3 cases for a visited node
			if (started[node] < started[neighbour])
				cout << "Forward Edge: " << node << " " << neighbour << "\n";
			else if (finished[neighbour] == -1)
				cout << "Back Edge (cycle): " << node << " " << neighbour << "\n";
			else
				cout << "Cross Edge: " << node << " " << neighbour << "\n";
		}
	}
	finished[node] = time++;
}

void classify_edges(GRAPH &graph) {
	int nodes = graph.size();

	vector<int> started(nodes, -1), finished(nodes, -1);
	int time = 1;

	for (int i = 0; i < nodes; ++i)
		if (started[i] == -1)	// not visited
			dfs(graph, i, started, finished, time);

	cout << "*****************************\n";
}

int main() {
	freopen("edge_classification-input", "rt", stdin);

	int cases, nodes, edges;
	cin >> cases;
	while (cases--) {
		cin >> nodes >> edges;

		GRAPH graph(nodes);	// observe: empty lists

		for (int e = 0; e < edges; ++e) {
			int from, to;
			cin >> from >> to;
			add_directed_edge(graph, from, to);
		}
		classify_edges(graph);
	}

	return 0;
}