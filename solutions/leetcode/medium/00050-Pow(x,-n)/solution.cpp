class Solution {
private:
    double f(double x, int n) {
        if (n == 0)
            return 1;

        double halfValue = f(x, n / 2);

        return n % 2 == 0 ? halfValue * halfValue : halfValue * halfValue * x;
    }

public:
    double myPow(double x, int n) {
        if (x == 0) return x;
        double result = f(x, n);
        return n < 0 ? 1 / result : result;
    }
};
