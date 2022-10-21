class Solution {
    bool
    hasCycle(int course, unordered_map<int, vector<int>> &connections, vector<bool> &visited, vector<bool> &on_stack) {
        if (on_stack[course]) return true;
        if (visited[course]) return false;

        visited[course] = true;
        on_stack[course] = true;

        for (int &c: connections[course])
            if (hasCycle(c, connections, visited, on_stack)) return true;

        on_stack[course] = false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        unordered_map<int, vector<int>> connections;
        vector<bool> visited = vector(numCourses, false);
        vector<bool> on_stack = vector(numCourses, false);
        for (auto &pre: prerequisites) connections[pre[1]].push_back(pre[0]);
        for (int i = 0; i < numCourses; ++i)
            if (hasCycle(i, connections, visited, on_stack)) return false;

        return true;
    }
};
