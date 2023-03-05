#define MOD 10000007

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) return -1;

        long long prime = 131, haystackHash = 0, needleHash = 0, power = 1;

        for (int i = 0; i < needle.length(); ++i) {
            needleHash = (((needleHash * prime) % MOD) + needle[i]) % MOD;
            haystackHash = (((haystackHash * prime) % MOD) + haystack[i]) % MOD;
            power = (power * prime) % MOD;
        }

        if (haystackHash == needleHash) return 0;

        for (int i = needle.length(); i < haystack.length(); ++i) {
            haystackHash += MOD;
            haystackHash = (haystackHash + MOD) * prime;
            haystackHash -= power * haystack[i - needle.length()];
            haystackHash = (haystackHash + haystack[i]) % MOD;

            int startIndex = i - needle.length() + 1;
            if (haystackHash == needleHash && needle == haystack.substr(startIndex, needle.length())) return startIndex;
        }

        return -1;
    }
};
