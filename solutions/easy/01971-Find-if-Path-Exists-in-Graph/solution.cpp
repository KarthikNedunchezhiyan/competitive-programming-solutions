class Solution {
private:
    vector<vector<int>> edgesMap;
    vector<bool> visitTracker;
    int destination;

    bool f(int cursor) {
        if (cursor == destination)
            return true;

        visitTracker[cursor] = true;

        for (int i: edgesMap[cursor])
            if (!visitTracker[i] && f(i))
                return true;

        return false;
    }

public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        this->destination = destination;
        this->visitTracker = vector(n, false);
        this->edgesMap.reserve(n);

        for (int i = 0; i < n; i++)
            this->edgesMap.emplace_back();

        for (vector<int> edge: edges) {
            this->edgesMap[edge[0]].push_back(edge[1]);
            this->edgesMap[edge[1]].push_back(edge[0]);
        }

        return f(source);
    }
};
