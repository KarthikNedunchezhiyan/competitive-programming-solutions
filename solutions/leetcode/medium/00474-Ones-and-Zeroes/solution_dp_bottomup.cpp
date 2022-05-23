class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        int N = strs.size();
        vector<int> onesInStr;
        onesInStr.reserve(N);
        vector<vector<int>> memo = vector(m + 1, vector(n + 1, 0));

        for (string &str: strs)
            onesInStr.push_back(count(str.begin(), str.end(), '1'));

        for (int k = 0; k < strs.size(); k++) {
            int oneCount = onesInStr[k], zeroCount = strs[k].size() - oneCount;

            for (int i = m; i >= zeroCount; i--)
                for (int j = n; j >= oneCount; j--)
                    memo[i][j] = max(memo[i][j], memo[i - zeroCount][j - oneCount] + 1);
        }

        return memo[m][n];
    }
};
