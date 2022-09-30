class Solution {
public:
    int firstUniqChar(string s) {
        int repeat[26] = {0};
        for (auto it = s.begin(); it != s.end(); it++) ++repeat[*it - 'a'];

        for (int i = 0; i < s.length(); ++i) if (repeat[s[i] - 'a'] == 1) return i;

        return -1;
    }
};
