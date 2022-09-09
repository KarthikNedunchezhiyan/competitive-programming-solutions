class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties) {
        sort(properties.begin(), properties.end(), [](vector<int> &prop1, vector<int> &prop2) {
            return (prop1[0] != prop2[0]) ? prop1[0] < prop2[0] : prop2[1] < prop1[1];
        });

        int max_so_far = properties.back()[1], result = 0;
        for (int i = properties.size() - 2; i >= 0; i--) {
            if (properties[i][1] < max_so_far) result++;
            else max_so_far = properties[i][1];
        }

        return result;
    }
};
