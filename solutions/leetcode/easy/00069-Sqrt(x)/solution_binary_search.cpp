class Solution {
private:
    int minDist = INT_MAX;
    int minDigit = INT_MAX;
    int x;

    int mySqrt(int left, int right) {
        if (left > right)
            return minDigit;

        long long middle = left + ((right - left) / 2);
        long long middleSquare = middle * middle;

        if (middleSquare == x)
            return middle;

        int dist = x - middleSquare;

        if (dist > 0 && dist < minDist) {
            minDist = dist;
            minDigit = middle;
        }

        return middleSquare > x ? mySqrt(left, middle - 1) : mySqrt(middle + 1, right);
    }

public:
    int mySqrt(int x) {
        this->x = x;
        return mySqrt(0, x);
    }
};
