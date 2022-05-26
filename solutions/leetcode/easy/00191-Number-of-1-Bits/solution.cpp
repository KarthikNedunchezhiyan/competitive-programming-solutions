class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = n & 1;
        while ((n = n >> 1) > 0)
            result += n & 1;

        return result;
    }
};
