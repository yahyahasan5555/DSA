#include <iostream>
#include <vector>

using namespace std;

// Insertion sort: grows a sorted prefix by inserting each element into it.
// Time:  O(n^2) worst/average, O(n) best case (already sorted).
// Space: O(1) extra.
void insertion_sort(vector<int>& vec) {
    int sz {(int) vec.size()};
 
    // The first value alone is already sorted,
    // so we start from the second one.
    for(int i {1}; i < sz; ++i) {
        int key {vec[i]};
        int j {i - 1};
 
        // Strict '>' keeps equal values in their original order (stable).
        while(j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j]; // Shift right.
            --j;
        }
 
        vec[j + 1] = key;
    }
}


//======================Testing==============
void test1(void) {
       // On arbitrary numbers:
       vector<int> arr {1, 4, 2, 6, 3, 4, 7, 5};
       insertion_sort(arr);

       for(int i {}; i < (int) arr.size(); ++i)
              cout << arr[i] << ' '; // 1 2 3 4 4 5 6 7
       cout << "\n**************************************" << endl;
}

void test2(void) {
       // On duplicate numbers:
       vector<int> arr = {2, 2, 2, 2, 1, 1, 2, 3, 3, 3, 1, 1, 1};
       insertion_sort(arr);

       for(int i {}; i < (int) arr.size(); ++i)
              cout << arr[i] << ' '; //  1 1 1 1 1 2 2 2 2 2 3 3 3
       cout << "\n**************************************" << endl;
}

void test3(void) {
       // On reversed-sorted array (Worst case):
       vector<int> arr = {8, 7, 6, 5, 4, 3, 2, 1};
       insertion_sort(arr);

       for(int i {}; i < (int) arr.size(); ++i)
              cout << arr[i] << ' '; // 1 2 3 4 5 6 7 8
       cout << "\n****************************************" << endl;
}

void test4(void) {
       // On almost-sorted array (from the best cases):
       vector<int> arr {1, 2, 3, 3, 2, 5, 6, 7, 8};
       insertion_sort(arr);

       for(int i {}; i < (int) arr.size(); ++i)
              cout << arr[i] << ' '; // 1 2 2 3 3 5 6 7 8
       cout << "\n***************************************" << endl;
} 


int main() {
       test1();
       test2();
       test3();
       test4();
       
       return 0;
}
