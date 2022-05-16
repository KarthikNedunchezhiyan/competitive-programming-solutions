#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S) {
        long long result = 0;
        sort(S.begin(), S.end());

        for (int i = 1; i < M; i++)
            result += (S[i] - S[i - 1] - 1 - K) / (K + 1);
  
        result += (S.front() - 1 )/ (K + 1);
        result += (N - S.back()) / (K + 1);

        return result;
}

