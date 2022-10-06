class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> monotonic_dec;
        vector<int> result;
        result.reserve(nums.size() - k + 1);

        for (int i = 0; i < nums.size(); ++i) {
            // removing the outdated from back
            while (!monotonic_dec.empty() && monotonic_dec.front() <= (i - k)) monotonic_dec.pop_front();
            // removing the non-participants from front
            while (!monotonic_dec.empty() && nums[monotonic_dec.back()] <= nums[i]) monotonic_dec.pop_back();

            monotonic_dec.emplace_back(i);
            if (i >= k - 1) result.emplace_back(nums[monotonic_dec.front()]);
        }

        return result;
    }
};
