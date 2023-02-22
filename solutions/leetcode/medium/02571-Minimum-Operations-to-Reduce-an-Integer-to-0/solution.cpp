class Solution {
public:
    int minStep(int target) {
        if (__builtin_popcount(target) == 1) return 0;

        int high = (1 << sizeof(int) * 8 - __builtin_clz(target));
        int low = high / 2;

        return min(minStep(high - target), minStep(target - low)) + 1;
    }

    int minOperations(int n) {
        return minStep(n) + 1;
    }
};
