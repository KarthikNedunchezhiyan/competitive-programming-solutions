class Solution {
    int f(int cursor, vector<vector<int>> &events, int event_left, vector<vector<int>> &memo) {
        if (cursor == events.size()) return 0;

        if (memo[cursor][event_left] != -1) return memo[cursor][event_left];

        int not_include = f(cursor + 1, events, event_left, memo);

        if (!event_left) return memo[cursor][event_left] = max(not_include, events[cursor][2]);

        auto next_itr = upper_bound(events.begin() + cursor + 1, events.end(), events[cursor][1],
                                    [](auto &target, auto &a) {
                                        return target < a[0];
                                    });

        return memo[cursor][event_left] = max(
                not_include,
                events[cursor][2] + f(next_itr - events.begin(), events, event_left - 1, memo)
        );
    }

public:
    int maxValue(vector<vector<int>> &events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>> memo = vector(events.size(), vector(k, -1));
        return f(0, events, k - 1, memo);
    }
};
