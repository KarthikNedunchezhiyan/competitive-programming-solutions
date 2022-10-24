class Solution {
    int combination(int cursor, vector<string> &arr, int mask, unordered_map<int, int> &memo) {
        if (cursor == arr.size()) return 0;

        int key = (mask << 4) + cursor;
        if (memo.count(key)) return memo[key];

        int n_mask = mask;
        for (char &c: arr[cursor]) {
            int bit_mask = 1 << (c - 'a');
            if ((n_mask & bit_mask) != 0) return memo[key] = combination(cursor + 1, arr, mask, memo);
            n_mask |= bit_mask;
        }

        return memo[key] = max((int) arr[cursor].size() + combination(cursor + 1, arr, n_mask, memo),
                               combination(cursor + 1, arr, mask, memo));
    }

public:
    int maxLength(vector<string> &arr) {
        unordered_map<int, int> memo;
        return combination(0, arr, 0, memo);
    }
};
