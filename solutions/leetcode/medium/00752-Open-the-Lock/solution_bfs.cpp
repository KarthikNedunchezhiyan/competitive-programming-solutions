class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        string initial = "0000";
        if (target == initial) return 0;

        unordered_set<string_view> dead_ends_set(deadends.begin(), deadends.end());
        if (dead_ends_set.count(initial)) return -1;

        unordered_set<string> visited = {initial};
        int distance = 0;
        queue<string> bfs;
        bfs.emplace(initial);

        while (!bfs.empty()) {
            int bfs_size = bfs.size();
            while (bfs_size--) {
                string current = bfs.front();
                bfs.pop();

                for (int i = 0; i < current.size(); ++i) {
                    string forward = current;
                    forward[i] = '0' + (((current[i] - '0') + 1) % 10);

                    string backward = current;
                    backward[i] = '0' + (((current[i] - '0') - 1) < 0 ? 9 : (current[i] - '0') - 1);

                    if (forward == target || backward == target) return distance + 1;

                    if (!visited.count(forward) && !dead_ends_set.count(forward)) {
                        bfs.emplace(forward);
                        visited.emplace(forward);
                    }
                    if (!visited.count(backward) && !dead_ends_set.count(backward)) {
                        bfs.emplace(backward);
                        visited.emplace(backward);
                    }
                }
            }

            ++distance;
        }

        return -1;
    }
};
