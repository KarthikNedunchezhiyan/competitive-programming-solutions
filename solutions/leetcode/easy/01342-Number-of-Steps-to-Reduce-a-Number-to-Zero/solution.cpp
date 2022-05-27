class Solution {
public:
    int numberOfSteps(int num) {
        if (!num) return 0;
        int result = 0;
        while (num > 0) {
            result += num & 1 ? 2 : 1;
            num >>= 1;
        }
        return result - 1;
    }
};
