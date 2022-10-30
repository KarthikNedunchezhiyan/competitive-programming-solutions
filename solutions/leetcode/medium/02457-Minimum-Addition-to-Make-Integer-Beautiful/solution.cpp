class Solution {
    int getDigitsSum(long long n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    long long makeIntegerBeautiful(long long n, int target) {
        int digits_sum = getDigitsSum(n);
        long long result = 0;
        long long multiples = 1;
        while (digits_sum > target) {
            int last_digit = n % 10;
            result += (10 - last_digit) * multiples;
            n += (10 - last_digit);
            n /= 10;
            multiples *= 10;

            digits_sum = getDigitsSum(n);
        }

        return result;
    }
};
