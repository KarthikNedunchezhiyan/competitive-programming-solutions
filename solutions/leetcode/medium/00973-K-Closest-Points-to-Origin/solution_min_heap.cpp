class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < points.size(); ++i) {
            auto point = points[i];
            pq.push({sqrt((point[0] * point[0]) + (point[1] * point[1])), i});
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> result;
        while (!pq.empty()) {
            result.emplace_back(points[pq.top().second]);
            pq.pop();
        }

        return result;
    }
};
