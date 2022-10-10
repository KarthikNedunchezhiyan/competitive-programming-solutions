class Solution {
private:
    int total_roots;

    int findParent(int node, int parents[]) {
        if (parents[node] == node) return node;
        return parents[node] = findParent(parents[node], parents);
    }

    bool makeUnion(int node1, int node2, int parents[]) {
        if (findParent(node1, parents) == findParent(node2, parents)) return false;

        parents[parents[node1]] = findParent(node2, parents);
        --total_roots;
        return true;
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections) {
        int parents[n], extra_connections = 0;
        total_roots = n;
        for (int i = 0; i < n; ++i) parents[i] = i;

        for (vector<int> &connection: connections)
            if (!makeUnion(connection[0], connection[1], parents)) ++extra_connections;

        return extra_connections >= (total_roots - 1) ? (total_roots - 1) : -1;
    }
};
