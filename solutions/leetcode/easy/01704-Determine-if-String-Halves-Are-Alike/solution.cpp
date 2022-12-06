class Solution {
    bool isVowel(char t) {
        if (t >= 97) t -= 32;
        return t == 'A' || t == 'E' || t == 'I' || t == 'O' || t == 'U';
    }

public:
    bool halvesAreAlike(string s) {
        int vowel_c = 0, i = 0, len_half = s.length() / 2;

        while (i < s.length()) {
            if (isVowel(s[i])) vowel_c += i < len_half ? 1 : -1;
            ++i;
        }

        return vowel_c == 0;
    }
};
