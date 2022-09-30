class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        vector<pair<int, int>> checkpoints;
        checkpoints.reserve(buildings.size() * 2);

        for (int i = 0; i < buildings.size(); ++i) {
            checkpoints.emplace_back(buildings[i][0], i);
            checkpoints.emplace_back(-buildings[i][1], i);
        }

        sort(checkpoints.begin(), checkpoints.end(), [&](pair<int, int> &checkpoint1, pair<int, int> &checkpoint2) {
            if (abs(checkpoint1.first) != abs(checkpoint2.first)) return abs(checkpoint1.first) < abs(checkpoint2.first);

            if (checkpoint1.first != checkpoint2.first) return checkpoint1.first > checkpoint2.first;

            return checkpoint1.first >= 0 ?
                buildings[checkpoint1.second][2] > buildings[checkpoint2.second][2]:
                buildings[checkpoint1.second][2] < buildings[checkpoint2.second][2];
        });

        priority_queue<pair<int, int>> height_queue;
        vector<vector<int>> result;

        for (pair<int, int> &checkpoint: checkpoints) {
            int building_index = checkpoint.second;
            vector<int> &building = buildings[building_index];

            if (checkpoint.first >= 0) {
                // starting
                if (height_queue.empty() || height_queue.top().first < building[2])
                    result.push_back({checkpoint.first, building[2]});

                height_queue.emplace(building[2], building_index);
            } else {
                // end
                if (checkpoint.second == height_queue.top().second) {
                    // clearance
                    while (!height_queue.empty() && (buildings[height_queue.top().second][1] <= buildings[checkpoint.second][1]))
                        height_queue.pop();

                    result.push_back({abs(checkpoint.first), height_queue.empty() ? 0 : height_queue.top().first});
                }
            }
        }

        return result;
    }
};
