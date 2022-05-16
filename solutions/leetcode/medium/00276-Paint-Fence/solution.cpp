#define MAX_CONSECUTIVE_SAME_COLOR 2

class Solution {
private:
    int k;
    vector<vector<vector<int>>> memo;

    int f(int fence_left, int prev_color_index, int color_left) {
        if (fence_left == 0)
            return 1;

        if (fence_left == 1)
            return color_left == 0 ? k - 1 : k;

        if (fence_left == 2)
            switch (color_left) {
                case 1:
                    return (k * k) - 1;
                case 0:
                    return (k - 1) * k;
                default:
                    return k * k;
            }

        if (prev_color_index != -1 && memo[fence_left][prev_color_index][color_left] != -1)
            return memo[fence_left][prev_color_index][color_left];

        int total_possibilities = 0;

        for (int ki = 0; ki < k; ki++) {
            if (ki == prev_color_index && color_left == 0)
                continue;

            total_possibilities += (ki == prev_color_index) ?
                                   f(fence_left - 1, ki, color_left - 1) :
                                   f(fence_left - 1, ki, MAX_CONSECUTIVE_SAME_COLOR - 1);
        }

        if (prev_color_index != -1)
            memo[fence_left][prev_color_index][color_left] = total_possibilities;

        return total_possibilities;
    }

public:
    int numWays(int n, int k) {
        this->k = k;
        this->memo = vector(n + 1, vector(k, vector(2, -1)));
        return f(n, -1, MAX_CONSECUTIVE_SAME_COLOR);
    }
};
