// https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/

// Time: O(n log n)
// Space: O(1).
class Solution {
public:
       int reductionOperations(vector<int>& nums) {
              sort(nums.rbegin(), nums.rend()); // from large to small

              int cnt {}, sz {(int) nums.size()};
              for(int i {}; i < sz - 1; ++i)
                     if(nums[i] != nums[i + 1])
                            cnt += i+1;
                     
              return cnt;
       }

};