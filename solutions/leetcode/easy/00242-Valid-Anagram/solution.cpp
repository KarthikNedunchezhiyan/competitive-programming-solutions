class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        int frequency[26] = {0};

        for (char i: s)
            frequency[i - 97]++;

        for (char i: t) {
            if (frequency[i - 97] <= 0)
                return false;
            frequency[i - 97]--;
        }

        return true;
    }
};
