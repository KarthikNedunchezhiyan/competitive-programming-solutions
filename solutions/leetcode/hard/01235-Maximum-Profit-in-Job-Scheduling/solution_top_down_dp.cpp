class Solution {
    int f(int cursor, vector<int> &sorted_idx, vector<int> &startTime, vector<int> &endTime, vector<int> &profit,
          vector<int> &memo) {
        if (cursor == sorted_idx.size()) return 0;

        if (memo[cursor] != -1) return memo[cursor];

        int non_include = f(cursor + 1, sorted_idx, startTime, endTime, profit, memo);
        auto next_itr = upper_bound(sorted_idx.begin() + cursor + 1, sorted_idx.end(), endTime[sorted_idx[cursor]],
                                    [&startTime](auto &target, auto &a) { return startTime[a] >= target; });

        return memo[cursor] = max(
                non_include,
                profit[sorted_idx[cursor]] +
                f(next_itr - sorted_idx.begin(), sorted_idx, startTime, endTime, profit, memo)
        );
    }

public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        vector<int> sorted_idx;
        for (int i = 0; i < startTime.size(); ++i) sorted_idx.push_back(i);

        sort(sorted_idx.begin(), sorted_idx.end(), [&startTime](auto &a, auto &b) {
            return startTime[a] < startTime[b];
        });

        vector<int> memo = vector(startTime.size(), -1);
        return f(0, sorted_idx, startTime, endTime, profit, memo);
    }
};
