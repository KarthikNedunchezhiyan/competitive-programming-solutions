class Solution {
private:
    string s;
    vector<string> wordDict;
    vector<int> memo;

    bool f(int start_index) {
        if (start_index == s.size())
            return true;

        if (memo[start_index] != -1)
            return memo[start_index];

        for (int i = 0; i < wordDict.size(); i++)
            if (s.compare(start_index, wordDict[i].length(), wordDict[i]) == 0)
                if (f(start_index + wordDict[i].size()))
                    return memo[start_index] = true;

        return memo[start_index] = false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict) {
        this->s = s;
        this->wordDict = wordDict;
        this->memo = vector(s.length(), -1);

        return f(0);
    }
};
