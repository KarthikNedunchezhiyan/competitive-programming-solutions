class Solution {
private:
    vector<vector<int>> edges;
    vector<vector<int>> result;
    vector<int> rank;
    vector<int> memo;
    int rankAllocator = 0;

    int f(int x, int parent) {
        if (memo[x] != -1)
            return memo[x];
        if (rank[x] != -1)
            return rank[x];

        rank[x] = rankAllocator++;

        int minRank = INT_MAX;
        for (int edge: edges[x])
            if (edge != parent) {
                int minAdjRank = f(edge, x);
                if (minAdjRank == INT_MAX || minAdjRank > rank[x])
                    result.push_back({x, edge});
                else
                    minRank = min(minRank, minAdjRank);
            }

        return memo[x] = minRank;
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
        rank = vector(n, -1);
        memo = vector(n, -1);
        edges.resize(n);
        for (vector<int> connection: connections) {
            edges[connection[0]].push_back(connection[1]);
            edges[connection[1]].push_back(connection[0]);
        }

        f(0, -1);

        return result;
    }
};
