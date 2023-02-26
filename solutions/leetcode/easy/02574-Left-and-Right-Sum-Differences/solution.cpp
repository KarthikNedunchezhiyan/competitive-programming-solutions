class Solution {
public:
    vector<int> leftRigthDifference(vector<int> &nums) {
        const int N = nums.size();
        vector<int> leftSum, rightSum, answer;
        int buffer = 0;
        for (int &num: nums) {
            leftSum.push_back(buffer);
            buffer += num;
        }

        buffer = 0;
        for (auto it = nums.rbegin(); it != nums.rend(); it++) {
            rightSum.push_back(buffer);
            buffer += *it;
        }

        std::reverse(rightSum.begin(), rightSum.end());

        for (int i = 0; i < N; ++i) answer.push_back(abs(leftSum[i] - rightSum[i]));
        return answer;
    }
};
