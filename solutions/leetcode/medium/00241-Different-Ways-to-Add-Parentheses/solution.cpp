enum Operator {
    ADD,
    SUB,
    MULT
};

typedef pair<Operator, int> token;

class Solution {
    int compute(int val1, Operator opr, int val2) {
        switch (opr) {
            case ADD:
                return val1 + val2;
            case SUB:
                return val1 - val2;
            case MULT:
                return val1 * val2;
        }
    }

    vector<int> diffWays(int si, int se, vector<token> &tokens) {
        if (si == se) return {tokens[si].second};
        if ((si + 1) == se) return {compute(tokens[si].second, tokens[se].first, tokens[se].second)};

        vector<int> comb;

        for (int i = si; i < se; ++i) {
            vector<int> comb1 = diffWays(si, i, tokens);
            vector<int> comb2 = diffWays(i + 1, se, tokens);

            for (int j = 0; j < comb1.size(); ++j)
                for (int k = 0; k < comb2.size(); ++k)
                    comb.push_back(compute(comb1[j], tokens[i + 1].first, comb2[k]));
        }

        return comb;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        vector<token> tokens;

        int cursor = 0, value = 0;
        Operator opr = ADD;

        while (cursor < expression.length()) {
            if (expression[cursor] >= '0' && expression[cursor] <= '9')
                value = (value * 10) + (expression[cursor] - '0');
            else {
                tokens.push_back({opr, value});
                opr = expression[cursor] == '+' ? ADD : expression[cursor] == '-' ? SUB : MULT;
                value = 0;
            }
            ++cursor;
        }
        tokens.push_back({opr, value});

        return diffWays(0, tokens.size() - 1, tokens);
    }
};
