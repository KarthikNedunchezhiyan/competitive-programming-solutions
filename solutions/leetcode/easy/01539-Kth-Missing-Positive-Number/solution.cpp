class Solution {
public:
    int findKthPositive(vector<int> &arr, int k) {
        int prev = 0;
        for (int &a: arr) {
            if ((prev + 1) < a) {
                int missing = a - prev - 1;
                if (missing < k) k -= missing;
                else return prev + k;
            }
            prev = a;
        }
        return prev + k;
    }
};
