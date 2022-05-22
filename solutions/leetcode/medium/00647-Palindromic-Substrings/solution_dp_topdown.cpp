class Solution {
private:
    vector<vector<int>> memo;
    int N;
    string s;

    bool isPalindrome(int start, int end) {
        if (start >= end)
            return true;

        if (memo[start][end] != -1)
            return memo[start][end];

        if (s[start] != s[end])
            return memo[start][end] = false;

        return memo[start][end] = isPalindrome(start + 1, end - 1);
    }

public:
    int countSubstrings(string s) {
        N = s.length();
        memo = vector(N, vector(N, -1));
        this->s = s;

        int totalPalindrome = 0;

        for (int i = 0; i < N; i++)
            for (int j = i; j < N; j++)
                if (isPalindrome(i, j))
                    totalPalindrome++;

        return totalPalindrome;
    }
};
