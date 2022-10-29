class Solution {
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime) {
        vector<int> sorted_indexes;
        for (int i = 0; i < plantTime.size(); ++i) {
            sorted_indexes.emplace_back(i);
        }

        std::sort(sorted_indexes.begin(), sorted_indexes.end(), [&](auto &a, auto &b) {
            return growTime[a] > growTime[b];
        });

        int max_days = INT_MIN, current_day = 0;

        for (auto &index: sorted_indexes) {
            max_days = max(max_days, current_day + plantTime[index] + growTime[index]);
            current_day += plantTime[index];
        }

        return max_days;
    }
};
