#define ctoi(c) c - 'a'

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1_freq[26] = {0};
        int s2_window_freq[26] = {0};
        int start = 0, unique_needed = 0, unique_present = 0;
        for (char &c: s1) if (++s1_freq[ctoi(c)] == 1) ++unique_needed;

        for (int i = 0; i < s2.length(); ++i) {
            if (++s2_window_freq[ctoi(s2[i])] == s1_freq[ctoi(s2[i])]) ++unique_present;

            while (s2_window_freq[ctoi(s2[i])] > s1_freq[ctoi(s2[i])]) {
                if (s2_window_freq[ctoi(s2[start])]-- == s1_freq[ctoi(s2[start])]) --unique_present;
                ++start;
            }

            if (unique_present == unique_needed) return true;
        }

        return false;
    }
};
