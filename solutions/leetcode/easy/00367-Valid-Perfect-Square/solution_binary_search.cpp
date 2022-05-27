class Solution {
private:
    int num;
    int search(int l, int r) {
        if (l > r)
            return -1;

        int mid = l + (r - l) / 2;
        if (num % mid == 0 && mid == num / mid) return mid;
        return mid > num / mid ? search(l, mid - 1) : search(mid + 1, r);
    }

public:
    bool isPerfectSquare(int num) {
        this->num = num;
        int sqrtVal = search(1, num);
        return !(sqrtVal == -1);
    }
};
