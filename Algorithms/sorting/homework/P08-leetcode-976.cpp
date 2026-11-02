// https://leetcode.com/problems/largest-perimeter-triangle/

// Time: O(n log n).
// Space: O(1);
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // Largest perimeter = largest three number in the array
        // valid to be a triangle.

        // sort reversed:
        sort(nums.rbegin(), nums.rend());

        // if the sum of the biggest two values 
        // after me is greater then me --> this is the ans.
        int sz {(int) nums.size()};
        for(int i {2}; i < sz; ++i)
            if(nums[i - 2] < nums[i] + nums[i - 1])
                // while the array sorted descending, 
                // it's guranteed that:
                // the first valid three value will be the ans.
                return nums[i] + nums[i - 1] + nums[i - 2];

        return 0; // there is no ans.
    }
};