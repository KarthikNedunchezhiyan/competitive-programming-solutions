class DisjointSets {
private:
    vector<int> rank;
    vector<int> parent;
    int total_roots;

public:
    DisjointSets(int size) {
        this->rank = vector(size, 1);
        this->parent.reserve(size);
        this->total_roots = size;

        for (int i = 0; i < size; i++)
            this->parent.push_back(i);
    }

    int findRoot(int target) {
        if (target == parent[target])
            return target;

        return parent[target] = findRoot(parent[target]);
    }

    void makeUnion(int x, int y) {
        int x_root = findRoot(x);
        int y_root = findRoot(y);

        if (x_root == y_root)
            return;

        if (rank[x_root] > rank[y_root])
            parent[y_root] = x_root;
        else if (rank[x_root] < rank[y_root])
            parent[x_root] = y_root;
        else {
            parent[y_root] = x_root;
            rank[x_root] += 1;
        }

        this->total_roots--;
    }

    int totalRoots() {
        return this->total_roots;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>> &edges) {
        DisjointSets disjoint_sets = DisjointSets(n);

        for (int i = 0; i < edges.size(); i++)
            disjoint_sets.makeUnion(edges[i][0], edges[i][1]);

        return disjoint_sets.totalRoots();
    }
};
