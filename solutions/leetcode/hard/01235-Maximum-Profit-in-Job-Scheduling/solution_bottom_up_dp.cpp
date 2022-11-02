class Solution {
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        vector<int> sorted_idx;
        for (int i = 0; i < startTime.size(); ++i) sorted_idx.push_back(i);

        sort(sorted_idx.begin(), sorted_idx.end(), [&startTime](auto &a, auto &b) {
            return startTime[a] < startTime[b];
        });

        vector<int> memo = vector(startTime.size() + 1, 0);

        for (int cursor = sorted_idx.size() - 1; cursor >= 0; --cursor) {
            int non_include = memo[cursor + 1];
            auto next_itr = upper_bound(sorted_idx.begin() + cursor + 1, sorted_idx.end(), endTime[sorted_idx[cursor]],
                                        [&startTime](auto &target, auto &a) { return startTime[a] >= target; });

            memo[cursor] = max(non_include, profit[sorted_idx[cursor]] + memo[next_itr - sorted_idx.begin()]);
        }

        return memo[0];
    }
};
