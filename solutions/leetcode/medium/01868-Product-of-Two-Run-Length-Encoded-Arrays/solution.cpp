class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>> &encoded1, vector<vector<int>> &encoded2) {
        int e1i = 0, e2i = 0;
        vector<vector<int>> result;

        while (e1i < encoded1.size() && e2i < encoded2.size()) {
            int product = encoded1[e1i][0] * encoded2[e2i][0];
            int sequence = min(encoded1[e1i][1], encoded2[e2i][1]);

            if (!result.empty() && result.back()[0] == product) result.back()[1] += sequence;
            else result.push_back({product, sequence});

            encoded2[e2i][1] -= sequence;
            encoded1[e1i][1] -= sequence;

            if (!encoded1[e1i][1]) ++e1i;
            if (!encoded2[e2i][1]) ++e2i;
        }

        return result;
    }
};
