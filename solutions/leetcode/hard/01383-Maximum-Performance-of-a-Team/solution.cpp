class Solution {
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
        vector<pair<int, int>> zipped;
        zipped.reserve(n);
        for (int i = 0; i < n; i++)
            zipped.emplace_back(speed[i], efficiency[i]);
        sort(zipped.begin(), zipped.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.second > b.second;
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        unsigned long sum = 0, performance = 0;

        for (pair<int, int> &entry: zipped) {
            if (pq.size() == k) {
                sum -= pq.top().first;
                pq.pop();
            }

            sum += entry.first;
            pq.push(entry);

            performance = max(performance, sum * entry.second);
        }

        return performance % 1000000007;
    }
};
