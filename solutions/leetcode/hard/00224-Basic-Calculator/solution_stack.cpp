class Solution {
public:
    int calculate(string s) {
        stack<int> table;
        int value = 0, sign = 1, i = 0, buffer = 0;

        while (i < s.length()) {
            if (s[i] >= '0' && s[i] <= '9') buffer = (buffer * 10) + (s[i] - '0');
            else if (s[i] == '(') {
                table.push(value);
                table.push(sign);
                sign = 1;
                value = 0;
            } else if (s[i] == ')') {
                value += sign * buffer;
                value *= table.top();
                table.pop();
                value += table.top();
                table.pop();
                buffer = 0;
            } else if (s[i] != ' ') {
                value += sign * buffer;
                buffer = 0;
                sign = s[i] == '-' ? -1 : 1;
            }
            ++i;
        }

        return value + (sign * buffer);
    }
};
