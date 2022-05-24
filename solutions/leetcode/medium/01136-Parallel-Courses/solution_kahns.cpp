class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>> &relations) {
        map<int, vector<int>> edges;
        vector<int> inDegree = vector(n + 1, 0);
        for (vector<int> relation: relations) {
            if (edges.find(relation[0]) == edges.end())
                edges[relation[0]] = {};
            if (edges.find(relation[1]) == edges.end())
                edges[relation[1]] = {};

            edges[relation[0]].push_back(relation[1]);
            inDegree[relation[1]]++;
        }


        queue<int> tpQ;
        int exploredNodes = 0, semesters = 0;
        for (int i = 1; i < n; i++)
            if (inDegree[i] == 0)
                tpQ.push(i);

        while (!tpQ.empty()) {
            int qSize = tpQ.size();
            semesters++;
            while (qSize-- > 0) {
                int node = tpQ.front();
                tpQ.pop();
                exploredNodes++;
                for (int child: edges[node])
                    if (--inDegree[child] == 0)
                        tpQ.push(child);
            }
        }

        return exploredNodes == n ? semesters : -1;
    }
};

