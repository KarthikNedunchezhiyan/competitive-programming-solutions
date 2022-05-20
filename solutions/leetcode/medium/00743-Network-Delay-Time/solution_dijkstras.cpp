#define INF INT_MAX
typedef pair<int, int> pqItem;

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        int minDist[n];
        fill_n(minDist, n, INF);

        map<int, vector<pair<int, int>>> edges;
        for (vector<int> &time: times) {
            auto it = edges.find(time[0]);
            if (it == edges.end()) edges[time[0]] = {};
            edges[time[0]].emplace_back(time[1], time[2]);
        }

        priority_queue<pqItem, vector<pqItem>, greater<>> pQ;
        pQ.push({0, k});

        while (!pQ.empty()) {
            pqItem item = pQ.top();
            pQ.pop();

            if (minDist[item.second - 1] != INF) continue;

            minDist[item.second - 1] = item.first;

            for (pair<int, int> edge: edges[item.second])
                if (minDist[edge.first - 1] == INF)
                    pQ.push({item.first == INF ? item.first : item.first + edge.second, edge.first});
        }

        int result = *max_element(minDist, minDist + n);
        return result == INF ? -1 : result;
    }
};
