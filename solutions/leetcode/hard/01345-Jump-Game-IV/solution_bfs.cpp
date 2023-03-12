class Solution {
public:
    int minJumps(vector<int> &arr) {
        unordered_map<int, vector<int>> similar;
        vector<bool> visited = vector(arr.size(), false);

        for (int i = 0; i < arr.size(); ++i) {
            if (similar.count(arr[i])) similar[arr[i]].push_back(i);
            else similar[arr[i]] = {i};
        }

        queue<int> bfs;
        bfs.push(0);
        visited[0] = true;
        int jumpCount = 0;

        while (!bfs.empty()) {
            int bfsSize = bfs.size();
            while (bfsSize--) {
                int index = bfs.front();
                bfs.pop();

                if (index == arr.size() - 1) return jumpCount;

                if ((index + 1) < arr.size() && !visited[index + 1]) {
                    visited[index + 1] = true;
                    bfs.push(index + 1);
                }
                if ((index - 1) >= 0 && !visited[index - 1]) {
                    visited[index - 1] = true;
                    bfs.push(index - 1);
                }

                if (similar.count(arr[index])) {
                    for (int &s: similar[arr[index]])
                        if (!visited[s]) {
                            visited[s] = true;
                            bfs.push(s);
                        }
                    similar[arr[index]].clear();
                }
            }
            ++jumpCount;
        }

        return jumpCount;
    }
};
