class Solution {
public:
    int minCost(string colors, vector<int> &neededTime) {
        int total_time = 0, max_time = 0, i = 0, j = 0, result = 0;
        while (j < colors.size()) {
            if (colors[i] == colors[j]) {
                total_time += neededTime[j];
                max_time = max(max_time, neededTime[j]);
            } else {
                if (i != j - 1) result += total_time - max_time;
                i = j;
                total_time = max_time = neededTime[j];
            }
            ++j;
        }

        return (i == j - 1) ? result : result + total_time - max_time;
    }
};
