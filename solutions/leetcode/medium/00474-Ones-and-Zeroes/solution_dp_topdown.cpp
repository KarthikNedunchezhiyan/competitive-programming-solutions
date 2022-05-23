class Solution {
private:
    vector<string> strs;
    vector<int> onesInStr;
    vector<vector<vector<int>>> memo;

    int N;

    int f(int cursor, int rem0, int rem1) {
        if (rem0 < 0 || rem1 < 0) return -1;

        if ((!rem0 && !rem1) || cursor >= N) return 0;

        if (memo[cursor][rem0][rem1] != -2)
            return memo[cursor][rem0][rem1];

        return memo[cursor][rem0][rem1] = max(
                1 + f(cursor + 1, rem0 - (strs[cursor].size() - onesInStr[cursor]), rem1 - onesInStr[cursor]),
                f(cursor + 1, rem0, rem1));
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        this->strs = strs;
        N = strs.size();
        onesInStr.reserve(N);
        memo = vector(N, vector(m + 1, vector(n + 1, -2)));

        for (string &str: strs)
            onesInStr.push_back(count(str.begin(), str.end(), '1'));

        return f(0, m, n);
    }
};
