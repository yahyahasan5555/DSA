#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

// Count sort: (Frequency version).
// Time: O(n + k) in every case, where k = max_val - min_val + 1, k = the range of values.
// Space: O(k) extra.
void count_sort(vector<int>& vec) {
       int sz {(int) vec.size()};
       if(sz <= 1) return;

       int max_val {vec[0]}, min_val {vec[0]};
       for(int& val: vec)
              max_val = max(max_val, val),
              min_val = min(min_val, val);

       // Shift by min_val, so the  smallest value maps to the index 0
       // (this way supports -ve values).
       // long long to hande overflow cases (Like: INT_MAX - INT_MIN)
       long long range {(long long) max_val - min_val + 1};
       vector<int> freq(range); // Initialized with zeros.

       // Compute the frequency for each value:
       for(int& i: vec)
              ++freq[(long long)i - min_val];

       // put the values back to the array:
       int cur_idx {};
       for(long long i {}; i < range; ++i) 
              for(long long j {}; j < freq[i]; ++j)
                     vec[cur_idx++] = (int) (i + min_val); 
}

//=============================Testing==============
void test1(void) {
       vector<int> arr {1, 2, 2, 1, 1, 1, 3, 3 ,4 ,4 , 1, 1, 1, 1, 6, 7, 8, 1};
       count_sort(arr);

       for(int i {}; i < (int) arr.size(); ++i)
              cout << arr[i] << ' '; // 1 1 1 1 1 1 1 1 1 2 2 3 3 4 4 6 7 8

       cout << "\n**************************************" << endl;
}


int main() {
       test1();

       return 0;
}
