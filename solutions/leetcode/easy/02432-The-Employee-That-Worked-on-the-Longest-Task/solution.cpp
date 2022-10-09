class Solution {
public:
    int hardestWorker(int n, vector<vector<int>> &logs) {
        int id = logs[0][0], diff = logs[0][1];

        for (int i = 1; i < logs.size(); ++i) {
            int c_diff = logs[i][1] - logs[i - 1][1];
            if (diff < c_diff) {
                diff = c_diff;
                id = logs[i][0];
            } else if (diff == c_diff && id > logs[i][0])
                id = logs[i][0];
        }

        return id;
    }
};
