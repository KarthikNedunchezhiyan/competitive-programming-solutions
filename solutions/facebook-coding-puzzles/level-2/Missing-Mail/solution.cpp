#include <bits/stdc++.h>
using namespace std;
// Write any include statements here
class Solution {
public:
    map<pair<int, double>, double> memo;
    vector<int> V;
    int C;
    double gain;

    double findMaxProfit(int cursor, double carry) {
        if (cursor >= V.size())
            return 0;

        pair<int, double> memoKey = pair<int, double>(cursor, carry);

        if (memo.find(memoKey) != memo.end())
            return memo[memoKey];

        double ifPick = carry + V[cursor] - C;
        double ifNPick = (carry + V[cursor]) * gain;

        if (ifPick >= ifNPick)
            return memo[memoKey] = ifPick + findMaxProfit(cursor + 1, 0);

        return memo[memoKey] = max(
                ifPick + findMaxProfit(cursor + 1, 0),
                findMaxProfit(cursor + 1, ifNPick));
    }

    double getMaxExpectedProfit(vector<int> &V, int C, double S) {
        this->V = V;
        gain = 1 - S;
        this->C = C;

        return gain == 1 ? accumulate(V.begin(), V.end(), -C) : findMaxProfit(0, 0);
    }
};

double getMaxExpectedProfit(int N, vector<int> V, int C, double S) {
        // Write your code here
        return (new Solution())->getMaxExpectedProfit(V, C, S);
}

