#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

class Solution {
private:
    long long getMinSeconds(int source, int destination, int N) {
        int minElement = min(source, destination), maxElement = max(source, destination);
        return min(maxElement - minElement, N - maxElement + minElement);
    }

public:
    long long getMinCodeEntryTime(int N, int M, vector<int> &C) {
        // Write your code here
        vector<long long> layerVal;
        layerVal.push_back(getMinSeconds(1, C[0], N));
        for (int i = 1; i < M; i++) {
            layerVal.push_back(layerVal[0] + getMinSeconds(1, C[i], N));

            for (int j = 1; j < i; j++)
                layerVal[i] = min(layerVal[i], layerVal[j] + getMinSeconds(C[j - 1], C[i], N));

            long long inc = getMinSeconds(C[i - 1], C[i], N);
            for (int j = 0; j < i; j++)
                layerVal[j] += inc;
        }

        return *min_element(layerVal.begin(), layerVal.end());
    }
};

long long getMinCodeEntryTime(int N, int M, vector<int> C) {
        // Write your code here
        return (new Solution())->getMinCodeEntryTime(N, M, C);
}

