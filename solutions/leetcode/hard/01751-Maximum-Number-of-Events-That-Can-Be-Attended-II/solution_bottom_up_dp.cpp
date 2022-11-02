class Solution {
public:
    int read(int i, int event_left, vector<vector<int>> &memo) {
        if (i == memo.size()) return 0;
        return memo[i][event_left];
    }

    int maxValue(vector<vector<int>> &events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>> memo = vector(events.size(), vector(k, -1));

        for (int cursor = events.size() - 1; cursor >= 0; --cursor) {
            for (int event_left = 0; event_left < k; ++event_left) {
                int not_include = read(cursor + 1, event_left, memo);
                if (!event_left) memo[cursor][event_left] = max(not_include, events[cursor][2]);
                else {
                    auto next_itr = upper_bound(events.begin() + cursor + 1, events.end(), events[cursor][1],
                                                [](auto &target, auto &a) {
                                                    return target < a[0];
                                                });

                    memo[cursor][event_left] = max(
                            not_include,
                            events[cursor][2] + read(next_itr - events.begin(), event_left - 1, memo)
                    );
                }
            }
        }

        return memo[0][k - 1];
    }
};
