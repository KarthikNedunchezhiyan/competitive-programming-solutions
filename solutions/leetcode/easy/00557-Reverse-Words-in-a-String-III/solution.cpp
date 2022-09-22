class Solution {
private:
    void concat(string &s, int start, int end, string &result) {
        for (int i = end; i >= start; --i) result += s[i];
    }

public:
    string reverseWords(string s) {
        int start = 0, i = start + 1;
        string result;
        for (; i < s.length(); ++i) {
            if (s[i] == ' ') {
                concat(s, start, i - 1, result);
                start = i + 1;
                result += ' ';
            }
        }
        concat(s, start, i - 1, result);

        return result;
    }
};
