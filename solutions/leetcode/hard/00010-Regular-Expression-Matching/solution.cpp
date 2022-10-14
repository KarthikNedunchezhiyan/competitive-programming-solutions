class Solution {
    bool compare(string_view s, string_view p) {
        if (s.empty() && p.empty()) return true;
        if (p.empty()) return false;

        if (p.size() >= 2 && p[1] == '*') {
            if (s.empty()) return compare(s, p.substr(2));
            bool first_match = (p[0] == '.') || (s[0] == p[0]);
            
            return compare(s, p.substr(2)) || (first_match && (compare(s.substr(1), p)));
        }

        if (!s.empty() && (p[0] == '.' || p[0] == s[0])) return compare(s.substr(1), p.substr(1));
        return false;
    }

public:
    bool isMatch(string s, string p) {
        return compare(string_view(s), string_view(p));
    }
};
