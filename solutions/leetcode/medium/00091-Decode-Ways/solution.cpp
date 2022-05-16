class Solution {
private:
    string s;
    vector<int> memo;

    int f(int si) {
        if (si >= s.length())
            return 1;

        if (s[si] == '0')
            return 0;

        if (memo[si] != -1)
            return memo[si];

        int res = f(si + 1);

        if (si < s.length() - 1 && ((s[si] == '1' && s[si + 1] >= '0' && s[si + 1] <= '9') ||
                                    (s[si] == '2' && s[si + 1] >= '0' && s[si + 1] <= '6'))) {
            res += f(si + 2);
        }

        return memo[si] = res;
    }

public:
    int numDecodings(string s) {
        this->s = s;
        this->memo = vector(s.length(), -1);
        return f(0);
    }
};
