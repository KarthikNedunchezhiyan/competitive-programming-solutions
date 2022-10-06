class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";

        unordered_map<char, int> t_freq;
        unordered_map<char, int> s_freq;

        int level = 0, ri = 0, rc = INT_MAX, start = 0;

        for (char &tc: t) ++t_freq[tc];

        for (int i = 0; i < s.length(); i++) {
            if (!t_freq.count(s[i])) continue;

            if (++s_freq[s[i]] == t_freq[s[i]]) ++level;

            while (start < s.length()) {
                if (t_freq.count(s[start])) {
                    if (level <= t_freq.size() && s_freq[s[start]] <= t_freq[s[start]]) break;

                    if (s_freq[s[start]]-- == t_freq[s[start]]) --level;
                }
                ++start;
            }

            if (level == t_freq.size() && rc > (i - start + 1)) {
                ri = start;
                rc = i - start + 1;
            }
        }

        return rc == INT_MAX ? "" : s.substr(ri, rc);
    }
};
