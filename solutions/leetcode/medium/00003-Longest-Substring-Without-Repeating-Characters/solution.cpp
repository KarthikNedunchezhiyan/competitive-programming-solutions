class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> indexLookup;
        int start = 0, result = 0;
        for (int i = 0; i < s.length(); ++i) {
            auto it = indexLookup.find(s[i]);
            if (it != indexLookup.end() && it->second >= start)
                start = it->second + 1;

            indexLookup[s[i]] = i;
            result = max(result, i - start + 1);
        }

        return result;
    }
};
