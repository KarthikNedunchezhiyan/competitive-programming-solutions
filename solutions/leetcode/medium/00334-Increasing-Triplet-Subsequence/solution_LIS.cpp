class Solution {
public:
    bool increasingTriplet(vector<int> &nums) {
        int max_sequence = 3;
        vector<int> seq;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (seq.empty() || seq.back() > nums[i]) seq.push_back(nums[i]);
            else {
                int cursor = seq.size() - 2;
                while (cursor >= 0 && seq[cursor] <= nums[i]) --cursor;
                seq[cursor + 1] = nums[i];
            }

            if (seq.size() >= max_sequence) return true;
        }

        return false;
    }
};
