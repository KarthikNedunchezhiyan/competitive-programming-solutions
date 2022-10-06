class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(!k) return 0;
        
        unordered_map<char, int> frequency;
        int start = 0, unique_count = 0, result = 0, i = 0;

        while (i < s.length()) {
            if (frequency[s[i]] || unique_count < k) {
                if (++frequency[s[i]] == 1) ++unique_count;
            } else {
                while (--frequency[s[start++]]);
                --unique_count;
                continue;
            }

            result = max(result, i++ - start + 1);
        }

        return result;
    }
};

