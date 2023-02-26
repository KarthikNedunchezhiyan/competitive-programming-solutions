class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> answer;
        long buffer = 0;
        for (char &w: word) {
            buffer = ((buffer * 10) + w - '0') % m;
            answer.push_back(buffer % m == 0);
        }
        return answer;
    }
};
