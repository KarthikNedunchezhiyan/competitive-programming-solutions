#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

long long getMinCodeEntryTime(int N, int M, vector<int> C) {
        // Write your code here
        long long result = 0;
        int source = 1;

        for (int destination: C) {
            if (source == destination)
                continue;

            int minElement = min(source, destination), maxElement = max(source, destination);
            result += min(maxElement - minElement, N - maxElement + minElement);
            source = destination;
        }

        return result;
}

