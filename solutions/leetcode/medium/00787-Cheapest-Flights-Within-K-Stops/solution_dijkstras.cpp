#define INF INT_MAX
// total_price, node, total_stops
typedef pair<int, pair<int, int>> pqItem;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        // generating the flight routes into edges map
        // node, edge, price
        map<int, vector<pair<int, int>>> edges;
        for (vector<int> flight: flights) {
            auto it = edges.find(flight[0]);
            if (it == edges.end())
                edges[flight[0]] = {};
            edges[flight[0]].emplace_back(flight[1], flight[2]);
        }

        int minStops[n];
        fill_n(minStops, n, INF);
        priority_queue<pqItem, vector<pqItem>, greater<>> pQ;
        pQ.push({0, {src, 0}});

        while (!pQ.empty()) {
            pqItem item = pQ.top();
            pQ.pop();

            // by nature of dijkstra's algorithm, first path to reach the node is always has cumulative min weight.
            if (item.second.first == dst)
                return item.first;

            if (item.second.second == k + 1 || minStops[item.second.first] <= item.second.second)
                continue;

            minStops[item.second.first] = item.second.second;

            for (pair<int, int> edge: edges[item.second.first])
                pQ.push({item.first + edge.second, {edge.first, item.second.second + 1}});
        }

        return -1;
    }
};
