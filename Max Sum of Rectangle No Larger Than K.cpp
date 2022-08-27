class Solution {
public:
    

    int maxSumSubmatrix(vector<vector<int>>& m, int k) {
    int result = INT_MIN, rows = m.size(), cols = m[0].size();
    for (int l = 0; l < cols; ++l) {
        vector<int> sums(rows);
        for (int r = l; r < cols; ++r) {
            for (int i = 0; i < rows; ++i) 
                sums[i] += m[i][r];
            set<int> s = {0};
            int run_sum = 0;
            for (int sum : sums) {
                run_sum += sum;
                auto it = s.lower_bound(run_sum - k);
                if (it != end(s))
                    result = max(result, run_sum - *it);
                s.insert(run_sum);
            }
        }
    }
    return result;
}  
};
