class Solution {
private:
    vector<int> days;
    vector<int> costs;
    vector<int> memo;

    int f(int i, int expiry) {
        if (i >= days.size())
            return 0;

        if (days[i] <= expiry)
            return f(i + 1, expiry);

        if (memo[i] != -1)
            return memo[i];

        return memo[i] = min(
                {costs[0] + f(i + 1, days[i]), costs[1] + f(i + 1, days[i] + 6), costs[2] + f(i + 1, days[i] + 29)});
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        this->days = days;
        this->costs = costs;
        this->memo = vector(days.size(), -1);

        return f(0, 0);
    }
};

// Time complexity is O(38 * n) ~= O(n)
