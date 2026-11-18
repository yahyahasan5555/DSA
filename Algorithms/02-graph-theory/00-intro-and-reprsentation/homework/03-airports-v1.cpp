#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct Edge {
       string to;
       int cost;

       Edge(string to, int cost): to(to), cost(cost) {}

       bool operator<(const Edge& other) const {
              if(this->to == other.to)    
                     return this->cost < other.cost;
              
              return this->to < other.to;
       }
};

using Graph = map<string, multiset<Edge>>;

// !THE COMPLEXITY ANALYSIS BELOW THE MAIN.

void add_directed_edge(Graph& graph, string from, string to, int cost) {
       graph[from].insert(Edge(to, cost));
}

void print_flights(const Graph& graph) {
       for(const auto& [from, s]: graph) {
              cout << "Flights From " << from << ":\n";
              
              for(const auto& [to, cost]: s) 
                     cout << "\tTo " << to << " with cost " << cost << '\n';
       }
}

int main() {
       int nodes, edges; cin >> nodes >> edges;
       Graph graph;

       for(int e {}; e < edges; ++e) {
              string from, to; cin >> from >> to;
              int cost; cin >> cost;

              add_directed_edge(graph, from, to, cost);
       }

       print_flights(graph);
       return 0;
}

/*

sh-5.3$ g++ 03-airports-v1.cpp -o airports.out
sh-5.3$ ./airports.out 
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

Flights From California:
        To Florida with cost 75
        To Pennsylvania with cost 37
        To Texas with cost 10
        To Texas with cost 30
        To Texas with cost 35
Flights From Florida:
        To California with cost 70
Flights From NewYork:
        To California with cost 35
Flights From Pennsylvania:
        To Florida with cost 18
        To Florida with cost 28


 * Complexity analysis:
       * Note: both maps and sets are balanced binary Search Trees (BBSTs).
       * NOTE: I ignored the string comparison for simplicity.
       - For inserting function:
              * Time:
                     - O(log V) --> for access the map's key
                     - O(log neighbors) suppose neighbors may be = n.of Edges then: O(log E)
                     - Total time for insertion: O(log V + log E)
              * Space:
                     - O(1)
                     
       - Print function:
              * Time:
                     - O(V) for the outer loop (map's loop over all keys/V)
                     - O(E) for the inner loops cause the sum of all of the iterations for all inner loops will be = E
                     - so, The total complexity for printing: O(V + E).
              * Space:
                     - O(1)
       - main function:
              * Time:
                     - insert one edge: O(log V + log E) as we said above.
                     - insert all edges: O(E * (log V + log E)).
                     - Print O(V + E) as we said above.
                     - Then the total: O(E * (log V + log E) + V + E)
              * Extra Space:
                     - O(V) for inserting keys in the outer map.
                     - O(E) for inserting flights as edges, since every flight stored exactly once.
                     - Total: O(V + E)
 */