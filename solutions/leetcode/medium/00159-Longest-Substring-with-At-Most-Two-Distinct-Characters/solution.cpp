#define MAX 2

class Solution {
private:
    int frequency[MAX];
    char pool[MAX];

    bool accommodate(char &t) {
        for (int i = 0; i < MAX; i++)
            if (pool[i] == t || frequency[i] == 0) {
                pool[i] = t;
                return ++frequency[i];
            }
        return false;
    }

    int freeUpOne(string &s, int start) {
        while (start < s.length()) {
            for (int i = 0; i < MAX; i++)
                if (pool[i] == s[start]) {
                    if (--frequency[i] == 0) return start + 1;
                    break;
                }
            start++;
        }
        return -1;
    }

public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int start = 0, result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (!accommodate(s[i])) {
                start = freeUpOne(s, start);
                accommodate(s[i]);
            }
            result = max(result, i - start + 1);
        }
        return result;
    }
};
