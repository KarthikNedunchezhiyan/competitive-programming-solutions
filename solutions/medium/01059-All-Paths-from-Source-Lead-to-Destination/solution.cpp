class Solution {
    int destination;
    map<int, vector<int>> edgesMap;
    vector<bool> visitTracker;

    bool f(int cursor) {
        if (cursor != destination) {
            if (visitTracker[cursor] || edgesMap[cursor].empty())
                return false;

            visitTracker[cursor] = true;

            for (int i: edgesMap[cursor])
                if (!f(i)) return false;
        }

        visitTracker[cursor] = false;

        return true;
    }

public:
    bool leadsToDestination(int n, vector<vector<int>> &edges, int source, int destination) {
        visitTracker = vector(n, false);
        this->destination = destination;

        for (vector<int> edge: edges)
            if (edge[0] == destination)
                return false;
            else if (edgesMap.find(edge[0]) == edgesMap.end())
                edgesMap[edge[0]] = {edge[1]};
            else
                edgesMap[edge[0]].push_back(edge[1]);

        return f(source);
    }
};
