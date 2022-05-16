class DisjointSets {
private:
    vector<int> rank;
    vector<int> parent;

    int findRoot(int target) {
        if (target == parent[target])
            return target;

        return parent[target] = findRoot(parent[target]);
    }

public:
    DisjointSets(int size) {
        this->rank = vector(size, 1);
        this->parent.reserve(size);

        for (int i = 0; i < size; i++)
            this->parent.push_back(i);
    }

    void makeUnion(int x, int y) {
        int x_root = findRoot(x);
        int y_root = findRoot(y);

        if (rank[x_root] > rank[y_root])
            parent[y_root] = x_root;
        else if (rank[x_root] < rank[y_root])
            parent[x_root] = y_root;
        else {
            parent[y_root] = x_root;
            rank[x_root] += 1;
        }
    }

    int totalRoots() {
        int distinct_provinces = 0;
        
        for (int i = 0; i < parent.size(); i++)
            if (i == parent[i])
                distinct_provinces++;
            
        return distinct_provinces;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        DisjointSets disjoint_sets = DisjointSets(isConnected.size());
        int m = isConnected.size(), n = isConnected[0].size();
        for (int i = 0; i < m; i++)
            for (int j = i + 1; j < n; j++)
                if (isConnected[i][j])
                    disjoint_sets.makeUnion(i, j);

        return disjoint_sets.totalRoots();
    }
};
