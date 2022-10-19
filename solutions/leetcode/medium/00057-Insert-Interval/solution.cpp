class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        if (intervals.empty() || intervals.back()[1] < newInterval[0]) {
            intervals.push_back(newInterval);
            return intervals;
        }

        vector<vector<int>> result;
        int i = 0;
        for (; i < intervals.size(); ++i)
            if (newInterval[0] <= intervals[i][1]) {
                if (intervals[i][0] <= newInterval[1])
                    result.push_back({min(intervals[i][0], newInterval[0]), max(newInterval[1], intervals[i][1])});
                else {
                    result.emplace_back(newInterval);
                    result.emplace_back(intervals[i]);
                }
                break;
            } else result.emplace_back(intervals[i]);

        for (++i; i < intervals.size(); ++i)
            if (intervals[i][1] >= result.back()[1]) {
                if (intervals[i][0] <= result.back()[1]) result.back()[1] = intervals[i][1];
                else result.emplace_back(intervals[i]);
            }

        return result;
    }
};
