// https://leetcode.com/problems/sort-an-array/

// Time: O(n + range), where range = max_val - min_val + 1;
// Space: O(range) extra.
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // With count sort:

        int max_range = 5e4;
        int min_range = -5e4;

        int range = max_range - min_range + 1;
        vector<int> freq(range);

        for(const int& x: nums)
            ++freq[x - min_range];

        int idx {};
        for(int i {}; i < range; ++i)
            for(int j {}; j < freq[i]; ++j)
                nums[idx++] = (i + min_range);

        return nums;
    }
};