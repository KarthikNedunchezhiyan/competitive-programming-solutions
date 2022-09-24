class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList) {
        vector<vector<int>> result;
        int fi = 0, si = 0;

        while (fi < firstList.size() && si < secondList.size()) {
            if (!(firstList[fi][1] < secondList[si][0] || secondList[si][1] < firstList[fi][0]))
                result.push_back({max(firstList[fi][0], secondList[si][0]), min(firstList[fi][1], secondList[si][1])});

            if (firstList[fi][1] <= secondList[si][1]) ++fi;
            else ++si;
        }

        return result;
    }
};
