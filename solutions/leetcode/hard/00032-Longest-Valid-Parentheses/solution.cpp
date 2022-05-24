class Solution {
private:
    int squash(stack<int> &Q) {
        int totalValid = 0;
        while (!Q.empty() && Q.top() < 0) {
            totalValid += -1 * Q.top();
            Q.pop();
        }

        return totalValid;
    }

public:
    int longestValidParentheses(string s) {
        stack<int> Q;
        int si = -1, result = 0;

        while (++si < s.length()) {
            char elm = s[si];

            if (elm == ')' && Q.empty())
                continue;

            if (elm == ')') {
                int totalValid = squash(Q);

                if (!Q.empty()) {
                    Q.pop();
                    totalValid += 2 + squash(Q);
                    Q.emplace(-1 * totalValid);
                }

                result = max(result, totalValid);
            } else
                Q.emplace(si);
        }

        return result;
    }
};
