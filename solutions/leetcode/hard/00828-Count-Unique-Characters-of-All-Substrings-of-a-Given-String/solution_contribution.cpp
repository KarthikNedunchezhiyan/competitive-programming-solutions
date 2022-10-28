class Solution {
public:
    int uniqueLetterString(string s) {
        const int N = s.length();
        int last_seen[26];
        vector<int> left_stretch;
        left_stretch.reserve(s.length());

        memset(last_seen, -1, sizeof(last_seen));
        for (int i = 0; i < s.length(); ++i) {
            if (last_seen[s[i] - 'A'] == -1) left_stretch.push_back(i + 1);
            else left_stretch.push_back(i - last_seen[s[i] - 'A']);
            last_seen[s[i] - 'A'] = i;
        }

        memset(last_seen, -1, sizeof(last_seen));
        int result = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            int right_stretch = last_seen[s[i] - 'A'] == -1 ? s.length() - i : last_seen[s[i] - 'A'] - i;
            result += right_stretch * left_stretch[i];
            last_seen[s[i] - 'A'] = i;
        }

        return result;
    }
};
