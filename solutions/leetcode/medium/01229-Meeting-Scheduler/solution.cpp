class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>> &slots1, vector<vector<int>> &slots2, int duration) {
        int s_i = 0, s_j = 0;
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());

        while ((s_i < slots1.size()) && (s_j < slots2.size())) {
            int start = max(slots1[s_i][0], slots2[s_j][0]);
            int end = min(slots1[s_i][1], slots2[s_j][1]);

            if ((end - start) >= duration) return {start, start + duration};

            if (slots1[s_i][1] < slots2[s_j][1]) ++s_i;
            else ++s_j;
        }

        return {};
    }
};
