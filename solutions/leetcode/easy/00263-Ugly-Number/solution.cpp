class Solution {
public:
    bool isUgly(int n) {
        for (auto div: {2, 3, 5}) while (n && !(n % div)) n /= div;
        return n == 1;
    }
};
