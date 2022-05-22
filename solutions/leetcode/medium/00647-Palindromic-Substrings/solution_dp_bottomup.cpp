class Solution {
public:
    int countSubstrings(string s) {
        int N = s.length();
        vector<vector<bool>> palindrome = vector(N, vector(N, true));
        int totalPalindrome = N;
        for (int i = N - 1; i >= 0; i--)
            for (int j = i + 1; j < N; j++) {
                palindrome[i][j] = s[i] == s[j] && palindrome[i + 1][j - 1];
                totalPalindrome += palindrome[i][j];
            }

        return totalPalindrome;
    }
};
