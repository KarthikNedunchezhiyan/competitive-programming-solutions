class Solution {
public:
    void reverseString(vector<char> &s) {
        int cursor = -1;
        while (++cursor < (s.size() / 2)) swap(s[cursor], s[s.size() - cursor - 1]);
    }
};
