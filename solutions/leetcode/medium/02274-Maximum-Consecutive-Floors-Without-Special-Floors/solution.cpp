class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int> &special) {
        sort(special.begin(), special.end(), [](int &a, int &b) {
            return a < b;
        });

        int maxSpace = max(special.front() - bottom, top - special.back());

        for (int i = 1; i < special.size(); i++) {
            maxSpace = max(maxSpace, special[i] - special[i - 1] - 1);
        }

        return maxSpace;
    }
};
