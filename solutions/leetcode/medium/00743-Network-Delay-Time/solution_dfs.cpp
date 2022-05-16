class Solution {
private:
    // map<node, vector<pair<adjacentNode, delayTime>>
    map<int, vector<pair<int, int>>> edgesMap;
    vector<int> minDelay;

    void findMinDelay(int cursor, int delay) {
        if (minDelay[cursor] <= delay)
            return;

        minDelay[cursor] = delay;

        for (pair<int, int> edge: edgesMap[cursor])
            findMinDelay(edge.first, delay + edge.second);
    }

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        minDelay = vector(n + 1, INT_MAX);
        for (vector<int> time: times) {
            if (edgesMap.find(time[0]) == edgesMap.end())
                edgesMap[time[0]] = {};

            edgesMap[time[0]].push_back(pair(time[1], time[2]));
        }

        for (auto &edge: edgesMap) {
            sort(edge.second.begin(), edge.second.end(), [](pair<int, int> &pair1, pair<int, int> &pair2) {
                return pair1.second < pair2.second;
            });
        }

        findMinDelay(k, 0);

        int result = INT_MIN;

        for (int i = 1; i < minDelay.size(); i++)
            if (minDelay[i] == INT_MAX)
                return -1;
            else
                result = max(result, minDelay[i]);

        return result;
    }
};
