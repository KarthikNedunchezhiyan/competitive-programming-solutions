class Solution {
private:
    string s1, s2, s3;
    vector<vector<int>> memo;

    int f(int i, int j) {
        int k = i + j;
        if (i >= s1.length())
            return !s3.compare(k, s3.length() - k, s2, j, s2.length() - j);

        if (j >= s2.length())
            return !s3.compare(k, s3.length() - k, s1, i, s1.length() - i);

        if (memo[i][j] != -1)
            return memo[i][j];

        int result = 0;

        if (s1[i] == s3[k])
            result = f(i + 1, j);

        if (!result && s2[j] == s3[k]) {
            result = f(i, j + 1);
        }

        return memo[i][j] = result;
    }

public:
    bool isInterleave(string s1, string s2, string s3) {
        if ((s1.length() + s2.length()) != s3.length())
            return false;

        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        this->memo = vector(s1.length(), vector(s2.length(), -1));

        return f(0, 0);
    }
};

// Time complexity O(s1_length * s2_length)
