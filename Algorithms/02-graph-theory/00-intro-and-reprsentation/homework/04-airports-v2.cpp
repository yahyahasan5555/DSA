#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct Edge {
       int from;
       int to;
       int cost;
       Edge(int from, int to, int cost): from(from), to(to), cost(cost) {}
};

// the order doesn't matter, so the best Data structure is the Vector.
typedef vector<Edge> Graph;

void add_directed_edge(Graph& graph, int from, int to, int cost) {
       graph.push_back(Edge(from, to, cost));
}

void print_graph(    const Graph& graph,
                     unordered_map<int, string>& id_to_airport) {
                            
       for(const Edge& e: graph) {
              cout << "Flight from " <<  id_to_airport[e.from] <<
                     " to " << id_to_airport[e.to] <<
                     " with cost " << e.cost << '\n';
       }
}

int main() {
       int nodes, edges; cin >> nodes >> edges;
       Graph graph;

       unordered_map<string, int> airport_to_id;
       unordered_map<int, string> id_to_airport;
       int cur_id {};

       for(int e {}; e < edges; ++e) {
              string from, to; cin >> from >> to;
              int cost; cin >> cost;

              if(!airport_to_id.count(from)) {
                     airport_to_id[from] = cur_id;
                     id_to_airport[cur_id] = from;
                     ++cur_id;
              }

              if(!airport_to_id.count(to)) {
                     airport_to_id[to] = cur_id;
                     id_to_airport[cur_id] = to;
                     ++cur_id;
              }

              add_directed_edge(graph, airport_to_id[from], airport_to_id[to], cost);
       }

       print_graph(graph, id_to_airport);
	return 0;
}

/*
sh-5.3$ g++ 04-airports-v2.cpp -o v2.out
sh-5.3$ ./v2.out 
5 9
California Texas 30
California Texas 10
Florida California 70
California Florida 75
NewYork California 35
Pennsylvania Florida 18
Pennsylvania Florida 28
California Texas 35
California Pennsylvania 37
Flight from California to Texas with cost 30
Flight from California to Texas with cost 10
Flight from Florida to California with cost 70
Flight from California to Florida with cost 75
Flight from NewYork to California with cost 35
Flight from Pennsylvania to Florida with cost 18
Flight from Pennsylvania to Florida with cost 28
Flight from California to Texas with cost 35
Flight from California to Pennsylvania with cost 37
*/


