class UnionFind {
private:
    vector<int> parents;
    vector<int> rank;
    int total_roots = 0;

    int findParent(int x) {
        if (parents[x] == x) return x;
        return parents[x] = findParent(parents[x]);
    }

public:
    UnionFind(int n) {
        rank = vector(n, 1);
        for (int i = 0; i < n; ++i) parents.push_back(i);
        total_roots = n;
    }

    void makeUnion(int x, int y) {
        int parent_x = findParent(x);
        int parent_y = findParent(y);

        if (parent_x == parent_y) return;

        if (rank[parent_x] > rank[parent_y]) parents[parent_y] = parent_x;
        else if (rank[parent_x] != rank[parent_y]) parents[parent_x] = parent_y;
        else {
            parents[parent_x] = parent_y;
            ++rank[parent_y];
        }
        
        --total_roots;
    }

    int totalRoots() {
        return total_roots;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>> &edges) {
        UnionFind uf = UnionFind(n);
        for (auto edge: edges) uf.makeUnion(edge[0], edge[1]);
        return uf.totalRoots();
    }
};
