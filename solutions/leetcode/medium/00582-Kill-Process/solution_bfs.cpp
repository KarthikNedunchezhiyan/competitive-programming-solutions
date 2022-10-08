class Solution {
public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        unordered_map<int, vector<int>> child_lookup;
        vector<int> result;
        queue<int> bfs;

        for (int i = 0; i < ppid.size(); ++i) child_lookup[ppid[i]].emplace_back(pid[i]);

        bfs.push(kill);
        while (!bfs.empty()) {
            for (int &child: child_lookup[bfs.front()])
                bfs.emplace(child);
            result.emplace_back(bfs.front());
            bfs.pop();
        }

        return result;
    }
};
