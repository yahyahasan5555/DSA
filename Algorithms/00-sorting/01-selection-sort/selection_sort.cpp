#include<iostream>
#include<vector>

using namespace std;

// Selection sort
// Time: O(n^2) in every cases (Best/Worst/Average).
// Space: O(1) extra.
void selection_sort(vector<int>& vec) {
       int sz {(int) vec.size()};

       // There is no need to reach to the last element,
       // because it'll be in its right place (Maximum place)
       // after all of this swaps.
       for(int i {}; i < sz - 1; ++i) {
              // Find the minimum element in the unsorted array
              // (unsorted part - including index i)
              int min_idx {i};
              for(int j {i + 1}; j < sz; ++j)
                     if(vec[j] < vec[min_idx])
                            min_idx = j;

              // Put the min in its right place.
              if(min_idx != i) 
                     swap(vec[min_idx], vec[i]);
       }
}


//=============================Testing==============
void test1(void) {
       // On arbitrary numbers:
       vector<int> arr {1, 4, 2, 6, 3, 4, 7, 5};
       selection_sort(arr);

       for(int i {}; i < (int) arr.size(); ++i)
              cout << arr[i] << ' '; // 1 2 3 4 4 5 6 7
       cout << "\n**************************************" << endl;
}

void test2(void) {
       // On duplicate numbers:
       vector<int> arr = {2, 2, 2, 2, 1, 1, 2, 3, 3, 3, 1, 1, 1};
       selection_sort(arr);

       for(int i {}; i < (int) arr.size(); ++i)
              cout << arr[i] << ' '; //  1 1 1 1 1 2 2 2 2 2 3 3 3
       cout << "\n**************************************" << endl;
}

void test3(void) {
       // On reversed array:
       vector<int> arr = {8, 7, 6, 5, 4, 3, 2, 1};
       selection_sort(arr);

       for(int i {}; i < (int) arr.size(); ++i)
              cout << arr[i] << ' '; // 1 2 3 4 5 6 7 8
       cout << "\n****************************************" << endl;
}

void test4(void) {
       // On almost-sorted array:
       vector<int> arr {1, 2, 3, 3, 2, 5, 6, 7, 8};
       selection_sort(arr);

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
