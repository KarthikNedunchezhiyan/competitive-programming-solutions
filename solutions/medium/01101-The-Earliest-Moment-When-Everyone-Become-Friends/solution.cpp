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
    int earliestAcq(vector<vector<int>> &logs, int n) {
        DisjointSets disjoint_sets = DisjointSets(n);

        sort(logs.begin(), logs.end(), [](vector<int> &x, vector<int> &y) {
            return x[0] < y[0];
        });

        for (int i = 0; i < logs.size(); i++) {
            disjoint_sets.makeUnion(logs[i][1], logs[i][2]);
            if (disjoint_sets.totalRoots() == 1)
                return logs[i][0];
        }

        return -1;
    }
};
