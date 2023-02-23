class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        const int N = profits.size();
        vector<pair<int, int>> merge;
        for (int i = 0; i < N; ++i) {
            merge.push_back({capital[i], profits[i]});
        }

        sort(merge.begin(), merge.end(), [](auto &a, auto &b) {
            return a.first < b.first;
        });

        priority_queue<int> pq;
        int index = 0;

        while (k) {
            while (index < N && merge[index].first <= w) pq.push(merge[index++].second);
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
            --k;
        }

        return w;
    }
};
