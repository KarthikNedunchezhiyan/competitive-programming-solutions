class Solution {
public:
    bool detectCapitalUse(string word) {
        for (int i = 2; i < word.length(); ++i)
            if ((isupper(word[i]) && islower(word[i - 1])) ||
                (islower(word[i]) && isupper(word[i - 1])))
                return false;
        return word[0] < 97 || word.length() == 1 || word[1] >= 97;
    }
};
