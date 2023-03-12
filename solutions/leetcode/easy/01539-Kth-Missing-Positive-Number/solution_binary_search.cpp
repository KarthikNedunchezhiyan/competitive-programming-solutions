class Solution {
public:
    int findKthPositive(vector<int> &arr, int k) {
        arr.insert(arr.begin(), 0);

        int left = 0, right = arr.size() - 1;

        while ((left + 1) < right) {
            int mid = left + (right - left) / 2;
            int leftMissing = arr[mid] - arr[left] - (mid - left);
            if (leftMissing >= k) right = mid;
            else {
                k -= leftMissing;
                left = mid;
            }
        }

        return (arr[left] + k) >= arr[right] ? arr[left] + k + 1 : arr[left] + k;
    }
};
