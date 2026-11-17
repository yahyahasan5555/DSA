// https://leetcode.com/problems/array-partition/

// Time: O(n log n).
// Space: O(1).
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans {}, sz {(int) nums.size()};
        for(int i {}; i < sz; i += 2)
            ans += nums[i];
        
        return ans;
    }
};