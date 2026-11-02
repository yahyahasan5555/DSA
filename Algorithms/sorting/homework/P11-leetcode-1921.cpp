// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/

// Time: O(n log n)
// Space O(n) --> arrive_time vector.
class Solution {
public:
       int eliminateMaximum(vector<int> dist, vector<int> speed) {
              int sz {(int) dist.size()};

              vector<int> arrive_time(sz);
              for(int i {}; i < sz; ++i)
                     arrive_time[i] = (dist[i] + speed[i] - 1) / speed[i];

              sort(arrive_time.begin(), arrive_time.end());

              int cnt {};
              for(int i {}; i < sz; ++i) {
                     if(arrive_time[i] - cnt > 0)
                            ++cnt;

                     else break;
              }

              return cnt;
       }
};