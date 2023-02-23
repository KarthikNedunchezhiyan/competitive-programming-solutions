class Solution {
    int getVal(vector<vector<int>> &lcp, int i, int j) {
        if (i >= lcp.size() || j >= lcp.size()) return 0;
        return lcp[i][j];
    }

public:
    string findTheString(vector<vector<int>> &lcp) {
        const int N = lcp.size();
        string word(N, 'a');

        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) {
                // upper bound check
                if (lcp[i][j] > N - j) return "";
                else if (!lcp[i][j]) {
                    if (word[i] == word[j]) word[j] = word[i] + 1;
                    if (word[j] > 'z') return "";
                } else for (int k = 0; k < lcp[i][j]; ++k) word[j + k] = word[i + k];
            }
        }

        for (int i = N - 1; i >= 0; --i)
            for (int j = N - 1; j >= i; --j) {
                int desired_value = (word[i] == word[j]) ? getVal(lcp, i + 1, j + 1) + 1 : 0;
                if (lcp[i][j] != desired_value || lcp[i][j] != lcp[j][i]) return "";
            }

        return word;
    }
};
