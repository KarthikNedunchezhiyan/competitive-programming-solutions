class Solution {
private:
    int rolling_rank_next = 0;

    int travel(int cursor, int parent, unordered_map<int, vector<int>> &bridges, int rank[], vector<vector<int>> &buffer) {
        if (rank[cursor] != -1) return rank[cursor];

        int min_rank = INT_MAX;
        rank[cursor] = rolling_rank_next++;

        if (bridges.count(cursor)) {
            for (int &adj: bridges[cursor]) {
                if (adj != parent) {
                    int _min_rank = travel(adj, cursor, bridges, rank, buffer);
                    if (_min_rank == INT_MAX) buffer.push_back({cursor, adj});
                    min_rank = min(min_rank, _min_rank);
                }
            }
        }

        return rank[cursor] > min_rank ? min_rank : INT_MAX;
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
        rolling_rank_next = 0;
        unordered_map<int, vector<int>> bridges;
        int rank[n];
        memset(rank, -1, sizeof(rank));
        vector<vector<int>> result;

        for (vector<int> &connection: connections) {
            bridges[connection[0]].push_back(connection[1]);
            bridges[connection[1]].push_back(connection[0]);
        }

        travel(0, -1, bridges, rank, result);
        return result;
    }
};

