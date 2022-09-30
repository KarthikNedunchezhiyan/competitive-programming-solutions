class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        int frequency[26] = {0};

        for (char i: s) frequency[i - 'a']++;

        for (char i: t) if (--frequency[i - 'a'] < 0) return false;

        return true;
    }
};
