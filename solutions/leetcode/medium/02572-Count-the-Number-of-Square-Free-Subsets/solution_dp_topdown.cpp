#define MOD 1000000007

class Solution {
    int permute(vector<int> &primeMasks, int index, int productMask, vector<vector<int>> &dp) {
        if (index >= primeMasks.size()) return 0;

        if (dp[index][productMask] != 0) return dp[index][productMask];

        int include = 0;
        if (!(productMask & primeMasks[index]))
            include = 1 + permute(primeMasks, index + 1, productMask | primeMasks[index], dp);
        return dp[index][productMask] =
                       ((include % MOD) + (permute(primeMasks, index + 1, productMask, dp) % MOD)) % MOD;
    }

public:
    int squareFreeSubsets(vector<int> &nums) {
        vector<vector<int>> dp = vector(1001, vector(1024, 0));
        int possiblePrimes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        vector<int> primeMasks;
        for (int &num: nums) {
            int mask = 0;
            bool satisfied = true;
            for (int i = 0; i < 10; ++i)
                if (num % possiblePrimes[i] == 0) {
                    num /= possiblePrimes[i];
                    if (num % possiblePrimes[i] != 0) mask |= 1 << i;
                    else {
                        satisfied = false;
                        break;
                    }
                }
            if (satisfied) primeMasks.push_back(mask);
        }

        return permute(primeMasks, 0, 0, dp);
    }
};
