class Solution {
private:
    vector<int> arr;
    int x;

    int search(int l, int r) {
        if (l == r || l + 1 == r)
            return _abs(l) <= _abs(r) ? l : r;

        int mid = (l + r) / 2;

        return arr[mid] - x >= 0 ? search(l, mid) : search(mid, r);
    }

    int _abs(int index) {
        if (index < 0 || index >= arr.size())
            return INT_MAX;

        return abs(x - arr[index]);
    }

public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        this->arr = arr;
        this->x = x;
        int leftCursor = search(0, arr.size() - 1);
        int rightCursor = leftCursor + 1;

        while (k-- > 1) {
            if (_abs(leftCursor - 1) <= _abs(rightCursor))
                leftCursor--;
            else
                rightCursor++;
        }

        return vector(arr.begin() + leftCursor, arr.begin() + rightCursor);
    }
};
