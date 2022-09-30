class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int pool[26] = {0};
        for (auto it = magazine.begin(); it != magazine.end(); it++) ++pool[*it - 'a'];

        for (int i = 0; i < ransomNote.length(); ++i) if (--pool[ransomNote[i] - 'a'] < 0) return false;

        return true;
    }
};
