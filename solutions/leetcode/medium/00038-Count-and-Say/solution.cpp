class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string prev_result = countAndSay(n - 1);
        string result = "";
        int i = 0, j = 0;
        while (j < prev_result.length()) {
            if (prev_result[j] != prev_result[i]) {
                result += to_string(j - i) + prev_result[i];
                i = j;
            }
            ++j;
        }
        return result += to_string(j - i) + prev_result[i];
    }
};
