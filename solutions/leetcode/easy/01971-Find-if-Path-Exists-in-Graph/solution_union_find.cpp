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

    void makeUnion(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);

        parent[y_root] = x_root;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        DisjointSet djSet = DisjointSet(n);

        for (vector<int> edge: edges)
            djSet.makeUnion(edge[0], edge[1]);

        return djSet.find(source) == djSet.find(destination);
    }
};
