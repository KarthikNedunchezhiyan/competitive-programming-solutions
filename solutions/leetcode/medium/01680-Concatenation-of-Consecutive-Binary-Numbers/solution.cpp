#define MOD 1000000007

class Solution {
public:
    int concatenatedBinary(int n) {
        long result = 0, bin_size = 0;
        for (int i = 1; i <= n; ++i) {
            if (__builtin_popcount(i) == 1) ++bin_size;
            result = ((result << bin_size) % MOD + i) % MOD;
        }
        return result;
    }
};
