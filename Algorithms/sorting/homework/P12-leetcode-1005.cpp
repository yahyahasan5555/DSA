// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

// Time: O(n log n).
// Space O(1) extra.
using ll = long long;

class Solution {
public:
       int largestSumAfterKNegations(vector<int> nums, int k) {
              sort(nums.begin(), nums.end());

              int i {}, sz {(int) nums.size()};
              while (i < sz && nums[i] < 0 && k)
                     nums[i] = -nums[i],
                     ++i, --k;

              ll sum {nums[0]};
              int mn {nums[0]};
              for (int i {1}; i < sz; ++i)
                     sum += nums[i],
                     mn = min(mn, nums[i]);

              if (k&1) sum -= 2 * mn;
              return (int) sum;
       }
};