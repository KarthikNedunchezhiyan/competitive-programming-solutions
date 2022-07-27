typedef pair<int, int> pqItem;

class Solution {
public:
    // Time complexity is O(N * logK)
    // This complexity will O(N * logN) when K = N; but this will never happen because we return input if K = N; :-)
    vector<int> topKFrequent(vector<int> &nums, int k) {
        // Logic to avoid worst case complexity [O(N * logN)]
        if (nums.size() == k)
            return nums;

        map<int, int> frequencies;
        for (int num: nums)
            frequencies[num]++;

        priority_queue<pqItem, vector<pqItem>, greater<>> pq;

        for (auto frequency: frequencies) {
            pq.push({frequency.second, frequency.first});
            if (pq.size() > k) pq.pop();
        }

        vector<int> result;
        result.reserve(k);
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
