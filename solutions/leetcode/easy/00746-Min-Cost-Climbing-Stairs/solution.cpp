class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int total_stairs = cost.size();

        if (total_stairs <= 2)
            return (total_stairs == 1) ? cost[0] : min(cost[0], cost[1]);

        int memo[total_stairs];
        memo[0] = cost[0];
        memo[1] = cost[1];

        for (int i = 2; i < total_stairs; i++) {
            memo[i] = min(memo[i - 2] + cost[i], memo[i - 1] + cost[i]);
        }

        return min(memo[total_stairs - 2], memo[total_stairs - 1]);
    }
};
