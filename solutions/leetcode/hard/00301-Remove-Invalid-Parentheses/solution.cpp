class Solution {
    unordered_set<string> visited;
public:
    vector<string> removeInvalidParentheses(string s) {
        if (visited.count(s)) return {};
        visited.insert(s);

        int open = 0, close = 0;
        vector<string> result;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') ++open;
            else if (s[i] == ')') {
                if (open) --open;
                else {
                    for (int j = i; j >= 0; --j) {
                        if (s[j] == ')') {
                            char temp = s[j];
                            s.erase(s.begin() + j);
                            vector<string> valid_strings = removeInvalidParentheses(s);
                            result.insert(result.end(), valid_strings.begin(), valid_strings.end());
                            s.insert(s.begin() + j, temp);
                        }
                    }
                    return result;
                }
            }
        }

        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == ')') ++close;
            else if (s[i] == '(') {
                if (close) --close;
                else {
                    for (int j = i; j < s.length(); ++j) {
                        if (s[j] == '(') {
                            char temp = s[j];
                            s.erase(s.begin() + j);
                            vector<string> valid_strings = removeInvalidParentheses(s);
                            result.insert(result.end(), valid_strings.begin(), valid_strings.end());
                            s.insert(s.begin() + j, temp);
                        }
                    }
                    return result;
                }
            }
        }

        return {s};
    }
};
