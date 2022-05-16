class Solution {
public:
    int largestCombination(vector<int> &candidates) {


        int result = -1;

        for (int i = 0; i < 32; i++) {
            int bitOneCount = 0;
            for (int &candidate: candidates) {
                bitOneCount += candidate & 1;
                candidate >>= 1;
            }

            result = max(result, bitOneCount);
        }

        return result;
    }
};
