#define MOD 1000000007

class Solution {
private:
    vector<int> valid_nums = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 6, 10, 14, 15, 21, 22, 26, 30};
    map<int, int> bit_factor_lookup;

    int recordPrimeFactors(int target, int flag) {
        if (!bit_factor_lookup.count(target)) {
            bit_factor_lookup[target] = 0;
            for (int i = 1; i <= 10; i++)
                if (target % valid_nums[i] == 0)
                    bit_factor_lookup[target] |= (1 << i);
        }

        return (flag & bit_factor_lookup[target]) != 0 ? -1 : flag | bit_factor_lookup[target];
    }

    long long calculate(int start, map<int, int> &frequency, int flag, vector<vector<int>> &memo) {
        if (start >= valid_nums.size() || frequency[valid_nums[start]] == 0) return 0;

        if ((flag = recordPrimeFactors(valid_nums[start], flag)) == -1) return 0;

        if (memo[start][flag] != -1) return memo[start][flag];

        long long total = 0;

        for (int i = start + 1; i < valid_nums.size(); i++)
            total = (total + (calculate(i, frequency, flag, memo) * frequency[valid_nums[start]])) % MOD;

        return memo[start][flag] = (frequency[valid_nums[start]] + total) % MOD;
    }

public:
    int numberOfGoodSubsets(vector<int> &nums) {
        map<int, int> frequency;
        vector<vector<int>> memo = vector(19, vector(2048, -1));

        for (int &num: valid_nums) frequency[num] = 0;

        for (int &num: nums) if (frequency.count(num)) frequency[num]++;

        long long total = 0;
        for (int i = 1; i < valid_nums.size(); i++)
            total = (total + calculate(i, frequency, 0, memo)) % MOD;

        for (int i = 0; i < frequency[1]; i++) total = (total << 1) % MOD;

        return total;
    }
};
