class DisjointSet {
    vector<int> parent;
    vector<int> rank;

    int find(int target) {
        if (parent[target] == target)
            return target;

        return parent[target] = find(parent[target]);
    }

public:
    DisjointSet(int size) {
        parent = vector<int>(size);
        rank = vector<int>(size);
        for (int i = 0; i < size; i++)
            parent[i] = i;
    }

    bool makeUnion(int a, int b) {
        int aRoot = find(a), bRoot = find(b);
        if (aRoot == bRoot)
            return false;

        if (rank[aRoot] > rank[bRoot])
            parent[bRoot] = aRoot;
        else if (rank[aRoot] < rank[bRoot])
            parent[aRoot] = bRoot;
        else {
            parent[aRoot] = bRoot;
            rank[bRoot] += 1;
        }

        return true;
    }
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>> &points) {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < points.size(); i++)
            for (int j = i + 1; j < points.size(); j++)
                edges.push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), {i, j}});
        sort(edges.begin(), edges.end());

        DisjointSet djSet = DisjointSet(points.size());
        int totalCost = 0, edgesIncluded = 0;
        for (pair<int, pair<int, int>> edge: edges)
            if (djSet.makeUnion(edge.second.first, edge.second.second)) {
                totalCost += edge.first;
                if (++edgesIncluded >= points.size() - 1)
                    break;
            }

        return totalCost;
    }
};
