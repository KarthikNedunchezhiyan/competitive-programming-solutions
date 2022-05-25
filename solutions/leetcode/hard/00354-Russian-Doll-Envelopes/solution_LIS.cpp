class Solution {
private:
    bool canFit(vector<int> &a, vector<int> &b) {
        return a[0] > b[0] && a[1] > b[1];
    }

public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        vector<int> LIS;
        LIS.reserve(envelopes.size());
        LIS.push_back(0);

        for (int i = 1; i < envelopes.size(); ++i) {
            if (canFit(envelopes[i], envelopes[LIS.back()])) {
                LIS.push_back(i);
                continue;
            }

            int k = 0;
            for (int j = LIS.size() - 2; j >= 0; --j)
                if (canFit(envelopes[i], envelopes[LIS[j]])) {
                    k = j + 1;
                    break;
                }
            LIS[k] = i;
        }

        return LIS.size();
    }
};
