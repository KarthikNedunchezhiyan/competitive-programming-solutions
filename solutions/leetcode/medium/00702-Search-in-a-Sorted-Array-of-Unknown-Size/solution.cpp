/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
private:
    int target;

    int search(ArrayReader reader, int l, int r) {
        if (l > r)
            return -1;

        int mid = (l + r) / 2;
        int readerRes = reader.get(mid);

        if (readerRes == target) return mid;

        return (readerRes == INT_MAX || readerRes > target) ? search(reader, l, mid - 1) : search(reader, mid + 1, r);
    }

public:
    int search(const ArrayReader &reader, int target) {
        this->target = target;

        return search(reader, 0, 10000);
    }
};
