// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
private:
    int search(int left, int right) {
        if (left > right)
            return left;

        int middle = left + (right - left) / 2;

        return isBadVersion(middle) ? search(left, middle - 1) : search(middle + 1, right);
    }

public:
    int firstBadVersion(int n) {
        return search(0, n - 1);
    }
};
