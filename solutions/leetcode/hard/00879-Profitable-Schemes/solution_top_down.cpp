#define MAX 101

int dp[MAX][MAX][MAX];

class Solution {
private:
    int
    f(int i, int mem_avail, int profit_need, const vector<int> &group, const vector<int> &profit) {
        if (mem_avail < 0) return 0;

        profit_need = profit_need < 0 ? 0 : profit_need;

        if (i >= group.size()) return profit_need == 0;

        if (dp[i][mem_avail][profit_need] != -1) return dp[i][mem_avail][profit_need];

        return dp[i][mem_avail][profit_need] =
                       (f(i + 1, mem_avail - group[i], profit_need - profit[i], group, profit) +
                        f(i + 1, mem_avail, profit_need, group, profit)) % 1000000007;
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit) {
        memset(dp, -1, sizeof(dp));
        return f(0, n, minProfit, group, profit);
    }
};
