class Solution {
public:
    string minWindow(string s1, string s2) {
        const int R = s2.length() + 1, C = s1.length() + 1;
        vector<int> memo = vector(C, -1);

        for (int i = 0; i < C; ++i) memo[i] = i;

        for (int i = R - 2; i >= 0; --i) {
            vector<int> current_row(C);
            current_row[C - 1] = -1;
            for (int j = C - 2; j >= 0; --j)
                if (s2[i] == s1[j]) current_row[j] = memo[j + 1];
                else current_row[j] = current_row[j + 1];
            memo = current_row;
        }

        int start, len = INT_MAX;
        for (int j = 0; j < C - 1; ++j)
            if (s2[0] == s1[j] && memo[j] != -1) {
                int c_len = memo[j] - j;
                if (c_len < len) {
                    len = c_len;
                    start = j;
                }
            }

        return len == INT_MAX ? "" : s1.substr(start, len);
    }
};
