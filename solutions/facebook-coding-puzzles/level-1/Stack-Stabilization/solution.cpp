#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int getMinimumDeflatedDiscCount(int N, vector<int> R) {
        // Write your code here
        int previous = INT_MAX;
        int inflationCount = 0;
        for (int i = N - 1; i >= 0; i--) {
            if (R[i] >= previous) {
                previous = previous - 1;
                inflationCount++;
            } else
                previous = R[i];

            if (previous <= i)
                return -1;
        }

        return inflationCount;
}

