#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

long long getArtisticPhotographCount(int N, string C, int X, int Y) {
        // Write your code here
        long long combinations = 0;
        vector<int> prefixSumB;
        vector<int> prefixSumP;
        prefixSumB.reserve(N);
        prefixSumP.reserve(N);

        prefixSumB.push_back(C[0] == 'B');
        prefixSumP.push_back(C[0] == 'P');

        for (int i = 1; i < N; i++) {
            prefixSumB.push_back(prefixSumB[i - 1] + (C[i] == 'B'));
            prefixSumP.push_back(prefixSumP[i - 1] + (C[i] == 'P'));
        }

        for (int i = 0; i < N; i++) {
            if (C[i] == 'A') {
                int frontS = i - Y - 1, frontE = i - X;
                int backS = i + X - 1, backE = i + Y;
                // adding case PAB
                combinations += ((frontE < 0 ? 0 : prefixSumP[frontE]) -
                                 (frontS < 0 ? 0 : prefixSumP[frontS])) *
                                ((backE >= N ? prefixSumB[N - 1] : prefixSumB[backE]) -
                                 (backS >= N ? prefixSumB[N - 1] : prefixSumB[backS]));
                // adding case BAP
                combinations += ((frontE < 0 ? 0 : prefixSumB[frontE]) -
                                 (frontS < 0 ? 0 : prefixSumB[frontS])) *
                                ((backE >= N ? prefixSumP[N - 1] : prefixSumP[backE]) -
                                 (backS >= N ? prefixSumP[N - 1] : prefixSumP[backS]));
            }
        }

        return combinations;
}

