class Solution {
    bool satisfied(int frequency[], int size, int k) {
        int max_number = INT_MIN, sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += frequency[i];
            max_number = max(max_number, frequency[i]);
        }

        return (sum - max_number) <= k;
    }

public:
    int characterReplacement(string s, int k) {
        int frequency[26] = {0}, start = 0, result = 1;
        for (int i = 0; i < s.length(); ++i) {
            ++frequency[s[i] - 'A'];
            while (!satisfied(frequency, 26, k)) --frequency[s[start++] - 'A'];
            result = max(result, i - start + 1);
        }

        return result;
    }
};
