class Solution {
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        map<int, vector<int>> edgesMap;
        for (vector<int> edge: edges) {
            if (edgesMap.find(edge[0]) == edgesMap.end())
                edgesMap[edge[0]] = {};
            if (edgesMap.find(edge[1]) == edgesMap.end())
                edgesMap[edge[1]] = {};

            edgesMap[edge[0]].push_back(edge[1]);
            edgesMap[edge[1]].push_back(edge[0]);
        }
        vector<bool> visitTracker = vector(n, false);
        queue<vector<int>> bfsQ;
        bfsQ.push({source});

        while (!bfsQ.empty()) {
            vector<int> &nextFirstPath = bfsQ.front();

            int lastVertices = nextFirstPath.back();
            if (lastVertices == destination)
                return true;

            visitTracker[lastVertices] = true;

            for (int vertex: edgesMap[lastVertices])
                if (!visitTracker[vertex]) {
                    vector<int> newPath;
                    newPath.reserve(nextFirstPath.size() + 1);

                    newPath.insert(newPath.begin(), nextFirstPath.begin(), nextFirstPath.end());
                    newPath.push_back(vertex);
                    bfsQ.push(newPath);
                }

            bfsQ.pop();
        }

        return false;
    }
};
