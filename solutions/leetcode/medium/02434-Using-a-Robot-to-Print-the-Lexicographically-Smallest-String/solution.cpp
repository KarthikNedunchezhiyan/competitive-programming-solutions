class Solution {
public:
    string robotWithString(string s) {
        map<char, int> last;
        for (int i = 0; i < s.length(); ++i) last[s[i] - 'a'] = i;

        stack<char> t;
        string result;
        result.reserve(s.length());
        int cursor = -1;

        for (auto &entry: last) {
            int next_small_idx = entry.second;

            while (!t.empty() && t.top() <= s[next_small_idx]) {
                result.push_back(t.top());
                t.pop();
            }

            for (int j = cursor + 1; j <= next_small_idx; ++j) {
                if (s[j] == s[next_small_idx]) result.push_back(s[j]);
                else t.emplace(s[j]);
            }

            cursor = max(cursor, next_small_idx);
        }

        while (!t.empty()) {
            result.push_back(t.top());
            t.pop();
        }

        return result;
    }
};

