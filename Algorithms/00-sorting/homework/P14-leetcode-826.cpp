// https://leetcode.com/problems/most-profit-assigning-work/
class Solution {
public:
       // Brute force ans:
       // for each worker check the max profit he can collect.
       // Time: O(n * m).
       // Space: O(1).
       int maxProfitAssignment1(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
              int sum {};
              for(int w: worker) {
                     int mx {};
                     for(int i {}; i < (int) profit.size(); ++i)
                            if(difficulty[i] <= w)
                                   mx = max(mx, profit[i]);
                     sum += mx;
              } return sum;
       }
       //----------------

       // the first ans come in my mind:
       // Time: O(n log n) (for sorting) + O(m * log n) for upper_bound
       // Space: O(n);
       int maxProfitAssignment2(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
              int n {(int) difficulty.size()}, m {(int) worker.size()};
              
              vector<array<int, 2>> pairs(n);
              for(int i {}; i < n; ++i) 
                     pairs[i] = {difficulty[i], profit[i]};
              sort(pairs.begin(), pairs.end());

              for(int i {1}; i < n; ++i)
                     pairs[i][1] = max(pairs[i][1], pairs[i - 1][1]);

              auto cmp_upper_bound = [](int val, const array<int, 2>& p) {
                     return val < p[0];
              };

              int sum {};
              for(int wor: worker) {
                     auto it {upper_bound(pairs.begin(), pairs.end(), wor, cmp_upper_bound)};
                     int idx {(int) (it - pairs.begin()) - 1};

                     if(idx < 0) continue; // this worker can't do any job
                     sum += pairs[idx][1];
              } return sum;
       } //----------------------------------------


       // Time: O(n log n + m log m) for sorting 2 vectors
       // Space: O(n) for pairs vector.
       int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
              int n {(int) difficulty.size()}, m {(int) worker.size()};
              vector<array<int, 2>> pairs(n);
              for(int i {}; i < n; ++i) pairs[i] = {difficulty[i], profit[i]};

              sort(pairs.begin(), pairs.end());
              sort(worker.begin(), worker.end());

              int max_profit_so_far {}, job_diff_idx {}, sum {};
              for(int i {}; i < m; ++i) {
                     while(job_diff_idx < n && worker[i] >= pairs[job_diff_idx][0])
                            max_profit_so_far = max(max_profit_so_far, pairs[job_diff_idx][1]),
                            ++job_diff_idx;
                     
                     sum += max_profit_so_far;
              }
              return sum;
       }
};
