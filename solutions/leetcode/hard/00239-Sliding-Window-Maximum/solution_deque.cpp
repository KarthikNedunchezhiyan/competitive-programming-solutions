class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> window;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            while (!window.empty() && window.front() <= (i - k)) window.pop_front();
            while (!window.empty() && nums[window.back()] < nums[i]) window.pop_back();
            window.emplace_back(i);

            if (i >= k - 1) result.emplace_back(nums[window.front()]);
        }

        return result;
    }
};
