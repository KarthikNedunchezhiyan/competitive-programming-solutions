class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string_view> pattern_lu;
        unordered_set<string_view> values;
        string_view view = s;
        int si = 0;
        for (int i = 0; i < pattern.size(); ++i, ++si) {
            if (si > s.length()) return false;
            int s_start = si;
            while (s[si] != ' ' && si != s.length()) si++;
            auto it = pattern_lu.find(pattern[i]);
            string_view value = view.substr(s_start, si - s_start);
            if (it != pattern_lu.end()) { if (it->second == value) continue; else return false; }
            if (values.count(value)) return false;
            pattern_lu[pattern[i]] = value;
            values.insert(value);
        }

        return si == s.length() + 1;
    }
};
