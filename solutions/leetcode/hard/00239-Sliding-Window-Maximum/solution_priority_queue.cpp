class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> result;
        result.reserve(nums.size() - k + 1);

        int i = 0;
        for (; i < k; ++i) pq.emplace(nums[i], i);
        result.push_back(pq.top().first);

        for (; i < nums.size(); ++i) {
            pq.emplace(nums[i], i);
            while (pq.top().second <= (i - k)) pq.pop();
            result.push_back(pq.top().first);
        }

        return result;
    }
};
