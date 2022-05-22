class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        map<int, vector<int>> edges;
        vector<int> inDegree = vector(numCourses, 0);
        queue<int> tpQ;
        vector<int> tpOrder;
        tpOrder.reserve(numCourses);

        for (vector<int> prerequisite: prerequisites) {
            auto it = edges.find(prerequisite[1]);
            if (it == edges.end())
                edges[prerequisite[1]] = {};

            edges[prerequisite[1]].push_back(prerequisite[0]);
            inDegree[prerequisite[0]]++;
        }

        for (int i = 0; i < numCourses; i++)
            if (inDegree[i] == 0)
                tpQ.push(i);

        while (!tpQ.empty()) {
            int currentNode = tpQ.front();
            tpQ.pop();

            inDegree[currentNode] = -1;

            tpOrder.push_back(currentNode);

            for (int edge: edges[currentNode]) {
                inDegree[edge]--;

                if (inDegree[edge] == 0)
                    tpQ.push(edge);
            }
        }

        return tpOrder.size() != numCourses ? vector<int>() : tpOrder;
    }
};
