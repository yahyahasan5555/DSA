// https://leetcode.com/problems/minimum-absolute-difference/

// Time: O(n log n)
// Space: O(2* (n-1))
class Solution {
public:
       static vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> res {{arr[0], arr[1]}};

        int sz {(int) arr.size()};
        for(int i {2}; i < sz; ++i) {
            int diff {arr[i] - arr[i - 1]};
            int prev_diff {res.back()[1] - res.back()[0]};

            if(diff > prev_diff) 
                continue;
            
            if(diff < prev_diff)
                res.clear();

            res.push_back({arr[i-1], arr[i]});
        }

        return res;
    }
};
