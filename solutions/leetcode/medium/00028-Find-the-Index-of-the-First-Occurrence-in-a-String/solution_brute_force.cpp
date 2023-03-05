class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            // special case mentioned in the "clarification" section.
            return 0;
        } else if (needle.length() > haystack.length()) {
            return -1;
        }

        int j;
        for (int i = 0; i < haystack.length() - needle.length() + 1; i++) {
            if (haystack[i] == needle[0]) {
                for (j = 1; j < needle.length(); j++) {
                    if (haystack[i + j] != needle[j])
                        break;
                }
                if (j == needle.length())
                    return i;
            }
        }

        return -1;
    }
};
