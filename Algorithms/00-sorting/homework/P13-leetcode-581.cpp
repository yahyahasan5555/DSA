//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

// Time: O(n log n) 
// Space: O(n)
class Solution {
public:
       // There is another optimized ans (O(n) time, O(1) extra space), 
       // but it doesn't dependent on the current topic (sorting).
       int _findUnsortedSubarray(vector<int>& nums) {
              vector<int> sorted(nums);
              sort(sorted.begin(), sorted.end());

              int sz {(int) nums.size()};

              int pointer1 {};
              while(pointer1 < sz && nums[pointer1] == sorted[pointer1])
                     ++pointer1;

              // The array is already sorted.
              if(pointer1 == sz)
                     return 0;

              int pointer2 {sz - 1};
              while(pointer2 >= 0 && nums[pointer2] == sorted[pointer2])
                     --pointer2;
              
              return pointer2 - pointer1 + 1;
       }
};
