class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int pool[26] = {0};
        for (auto it = magazine.begin(); it != magazine.end(); it++) ++pool[*it - 'a'];

        for (auto it = ransomNote.begin(); it != ransomNote.end(); it++) if (--pool[*it - 'a'] < 0) return false;

        return true;
    }
};
