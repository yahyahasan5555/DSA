// https://leetcode.com/problems/wiggle-sort/

class Solution {
public:
    // Time: O(n log n).
    // Space: O(n).
    void wiggleSort(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        int sz {(int) nums.size()}, p1 {}, p2 {sz - 1};
        vector<int> res(sz);

        int idx {};
        while(p1 < p2) {
            res[idx++] = nums[p1++];
            res[idx++] = nums[p2--];
        }

        if(p1 == p2) res[idx] = nums[p1];
        nums = res;
    }

    // Time: O(n log n) Time.
    // Space: O(1).
    void wiggleSort2(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for(int i {1}; i < (int) nums.size() - 1; i += 2)
            swap(nums[i], nums[i + 1]);
    }
}