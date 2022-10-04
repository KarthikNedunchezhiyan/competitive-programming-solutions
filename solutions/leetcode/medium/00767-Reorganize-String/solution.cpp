class Solution {
public:
    string reorganizeString(string s) {
        int frequency[26] = {0};
        for (char &c: s) ++frequency[c - 'a'];

        int max_elm_idx = distance(frequency, max_element(frequency, frequency + 26));
        if ((2 * frequency[max_elm_idx] - 1) > s.length()) return "";

        int cursor = 0;
        while (frequency[max_elm_idx]--) {
            s[cursor] = 'a' + max_elm_idx;
            cursor += 2;
        }

        for (int i = 0; i < 26; ++i) {
            while (frequency[i]-- > 0) {
                if (cursor >= s.length()) cursor = 1;
                s[cursor] = 'a' + i;
                cursor += 2;
            }
        }

        return s;
    }
};
