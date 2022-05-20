#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

class Solution {
private:
    // recursion-level, depth
    vector<int> pageDepth;
    vector<int> L;

    pair<int, int> recordPageDepth(int pageNo, int depth) {
        if (pageDepth[pageNo] > 0)
            return {INT_MAX, pageDepth[pageNo]};

        if (pageDepth[pageNo] != 0)
            return {(pageDepth[pageNo] * -1), depth - (pageDepth[pageNo] * -1)};

        pageDepth[pageNo] = -1 * depth;

        pair<int, int> depthInfo = recordPageDepth(L[pageNo] - 1, depth + 1);

        pageDepth[pageNo] = depthInfo.first <= depth ? depthInfo.second : depthInfo.second + 1;

        return {depthInfo.first, pageDepth[pageNo]};
    }

public:
    int getMaxVisitableWebpages(int N, vector<int> &L) {
        // Write your code here
        pageDepth = vector<int>(N, 0);
        this->L = L;
        int result = 0;
        for (int i = 0; i < N; i++)
            if (pageDepth[i] <= 0)
                result = max(result, recordPageDepth(i, 1).second);

        return result;
    }
};

int getMaxVisitableWebpages(int N, vector<int> L) {
  // Write your code here
  return (new Solution())->getMaxVisitableWebpages(N, L);
}

