#include <iostream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

bool is_valid(int r, int c, int rows, int cols) {
       return r >= 0 && r < rows && c >= 0 && c < cols;
}

int get_idx(int r, int c, int cols) {
       return r * cols + c;
}


void print_graph(int rows, int cols) {
       int direction_rows[] {1, -1, 0, 0};
       int direction_cols[] {0, 0, 1, -1};

       for(int r {}; r < rows; ++r) {
              for(int c {}; c < cols; ++c) {
                     cout << "Node " << get_idx(r, c, cols) << " has neighbors: ";
                     for(int d {}; d < 4; ++d) {
                            int new_r {r + direction_rows[d]}, new_c {c + direction_cols[d]};
                            if(is_valid(new_r, new_c, rows, cols))
                                   cout << get_idx(new_r, new_c, cols) << ' ';
                     } cout << endl;
              }
       }
}

int main() {
       int rows, cols; cin >> rows >> cols;

       print_graph(rows, cols);
       return 0;
}

/*
sh-5.3$ g++ 05-image-as-graph.cpp -o image.out
sh-5.3$ ./image.out 
3 4
Node 0 has neighbors: 4 1 
Node 1 has neighbors: 5 2 0 
Node 2 has neighbors: 6 3 1 
Node 3 has neighbors: 7 2 
Node 4 has neighbors: 8 0 5 
Node 5 has neighbors: 9 1 6 4 
Node 6 has neighbors: 10 2 7 5 
Node 7 has neighbors: 11 3 6 
Node 8 has neighbors: 4 9 
Node 9 has neighbors: 5 10 8 
Node 10 has neighbors: 6 11 9 
Node 11 has neighbors: 7 10 
*/