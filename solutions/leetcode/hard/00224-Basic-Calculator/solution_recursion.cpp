class Solution {
    // value, end_offset
    pair<int, int> read(int i, string &s) {
        if (s[i] == '(') return compute(i + 1, s);
        int value = 0;
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') value = (value * 10) + (s[i++] - '0');
        return {value, i - 1};
    }

    pair<int, int> compute(int i, string &s) {
        int total = 0, operation = 1;
        while (s[i] != ')' && i < s.length()) {
            if (s[i] == '+') operation = 1;
            else if (s[i] == '-') operation = -1;
            else if ((s[i] >= '0' && s[i] <= '9') || s[i] == '(') {
                auto temp = read(i, s);
                total += operation * temp.first;
                i = temp.second;
            }
            ++i;
        }

        return {total, i};
    }

public:
    int calculate(string s) {
        return compute(0, s).first;
    }
};
