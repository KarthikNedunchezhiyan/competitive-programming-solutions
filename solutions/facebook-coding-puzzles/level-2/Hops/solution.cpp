#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

long long getSecondsRequired(long long N, int F, vector<long long> P) {
        // Write your code here
        long long jumps = 0;
        sort(P.begin(), P.end());
        P.push_back(N);
        for (int i = 1; i < P.size(); i++)
            jumps += (P[i] - P[i - 1] - 1);

        return jumps + F;
}

