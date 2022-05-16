class DisjointSet {
private:
    vector<int> parent;

public:
    DisjointSet(int size) {
        parent.reserve(size);
        for (int i = 0; i < size; i++)
            parent.push_back(i);
    }

    int find(int target) {
        if (parent[target] == target)
            return target;

        return parent[target] = find(parent[target]);
    }

    void makeUnion(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);

        parent[root_a] = root_b;
    }
};

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int> &wells, vector<vector<int>> &pipes) {
        DisjointSet djSet = DisjointSet(n + 1);
        vector<vector<int>> edgesList;
        edgesList.reserve(n + pipes.size());

        // adding well's edges
        for (int i = 1; i <= n; i++)
            edgesList.push_back({0, i, wells[i - 1]});

        // house's edges
        for (int i = 0; i < pipes.size(); i++)
            edgesList.push_back({pipes[i][0], pipes[i][1], pipes[i][2]});

        sort(edgesList.begin(), edgesList.end(), [](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        });

        int result = 0;

        for (int i = 0; i < edgesList.size(); i++)
            if (djSet.find(edgesList[i][0]) != djSet.find(edgesList[i][1])) {
                djSet.makeUnion(edgesList[i][0], edgesList[i][1]);
                result += edgesList[i][2];
            }

        return result;
    }
};
