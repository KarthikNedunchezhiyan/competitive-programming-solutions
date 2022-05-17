#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int getArtisticPhotographCount(int N, string C, int X, int Y) {
        // Write your code here
        map<char, vector<int>> indexes;
        indexes['P'] = indexes['B'] = indexes['A'] = {};
        int combinationCount = 0;
        for (int i = 0; i < N; i++) {
            if (C[i] == '.')
                continue;

            if (C[i] == 'P' || C[i] == 'B') {
                char rPartner = C[i] == 'P' ? 'B' : 'P';
                for (auto it = lower_bound(indexes['A'].begin(), indexes['A'].end(), i - Y);
                     it != indexes['A'].end() && *it <= (i - X); it++)
                    for (auto it1 = lower_bound(indexes[rPartner].begin(), indexes[rPartner].end(), *it - Y);
                         it1 != indexes[rPartner].end() && *it1 <= (*it - X); it1++)
                        combinationCount++;
            }

            indexes[C[i]].push_back(i);
        }

        return combinationCount;
}

