class Solution {
public:
    int minimizeXor(int num1, int num2) {
        bool binary[32] = {false};
        int total_set = __builtin_popcount(num2);

        int cursor = 31, result = 0;
        while (num1) {
            binary[cursor--] = num1 & 1;
            num1 >>= 1;
        }

        for (int i = 0; i < 32; ++i) {
            if (!total_set) binary[i] = false;
            else if (binary[i]) --total_set;
        }

        for (int i = 31; i >= 0; --i) {
            if (total_set && !binary[i]) {
                binary[i] = true;
                --total_set;
            }
            if (binary[i])
                result |= 1 << (31 - i);
        }

        return result;
    }
};
