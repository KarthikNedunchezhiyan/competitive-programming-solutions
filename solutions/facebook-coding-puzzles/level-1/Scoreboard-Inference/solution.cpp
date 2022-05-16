#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int getMinProblemCount(int N, vector<int> S) {
        // Write your code here
        bool containsOdd = false;
        int maxScore = -1;
        for (int score: S) {
            if (score % 2 != 0)
                containsOdd = true;

            maxScore = max(maxScore, score);
        }
        
        return (maxScore % 2 == 0 && containsOdd) ? 1 + (maxScore / 2) : (maxScore + 1) / 2;
}

