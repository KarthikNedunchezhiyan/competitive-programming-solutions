class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (edges.size() == 0)
            return {0};

        vector<int> degree = vector(n, 0);
        map<int, vector<int>> edgesMap;

        for (vector<int> edge: edges) {
            if (edgesMap.find(edge[0]) == edgesMap.end())
                edgesMap[edge[0]] = {};
            if (edgesMap.find(edge[1]) == edgesMap.end())
                edgesMap[edge[1]] = {};

            edgesMap[edge[0]].push_back(edge[1]);
            edgesMap[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        deque<int> explore;
        for (int i = 0; i < degree.size(); i++)
            if (degree[i] == 1)
                explore.push_back(i);

        int yetToExplore = n;

        while (!explore.empty()) {
            if (!(yetToExplore -= explore.size()))
                return vector(explore.begin(), explore.end());

            int qSize = explore.size();

            while (qSize-- > 0) {
                int node = explore.front();
                explore.pop_front();

                for (int edge: edgesMap[node])
                    if (--degree[edge] == 1)
                        explore.push_back(edge);
            }
        }

        return {0};
    }
};
