class Solution {
private:
    int vowels_count = 5;
    int n;
    vector<vector<int>> memo;

    int f(int i, int j) {
        if (i >= n)
            return 1;

        if (memo[i][j] != -1)
            return memo[i][j];

        int result = 0;

        for (int k = j; k < vowels_count; k++)
            result += f(i + 1, k);

        return memo[i][j] = result;
    }

public:
    int countVowelStrings(int n) {
        this->n = n;
        this->memo = vector(n, vector(vowels_count, -1));
        return f(0, 0);
    }
};
