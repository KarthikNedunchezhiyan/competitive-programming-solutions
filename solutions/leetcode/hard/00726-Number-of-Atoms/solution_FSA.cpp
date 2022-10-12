enum State {
    NUMERIC = 0,
    PARENTHESIS = 1,
    ALPHA = 2
};

class Solution {
    int strToInt(string numeric_buffer) {
        int result = 0;
        for (auto it = numeric_buffer.rbegin(); it != numeric_buffer.rend(); it++) result = (result * 10) + (*it - '0');

        return !result ? 1 : result;
    }

    void adjustAtoms(string formula, int atoms_count, map<string, int> &atoms_map) {
        State current_state = NUMERIC;
        string numeric_buffer;
        string alpha_buffer;
        int cursor = formula.length() - 1;

        while (cursor >= 0) {
            switch (current_state) {
                case NUMERIC: {
                    if (formula[cursor] >= '0' && formula[cursor] <= '9') numeric_buffer += formula[cursor--];
                    else if (formula[cursor] == ')' || formula[cursor] == '(') current_state = PARENTHESIS;
                    else if (formula[cursor] >= 'A' && formula[cursor] <= 'z') current_state = ALPHA;
                    break;
                }
                case PARENTHESIS: {
                    if (formula[cursor] == '(') return;
                    adjustAtoms(formula.substr(0, cursor), atoms_count * strToInt(numeric_buffer), atoms_map);
                    numeric_buffer.clear();
                    int close_parenthesis = 1;
                    while (close_parenthesis) {
                        --cursor;
                        if (formula[cursor] == '(') --close_parenthesis;
                        else if (formula[cursor] == ')') ++close_parenthesis;
                    }
                    --cursor;
                    current_state = NUMERIC;
                    break;
                }
                case ALPHA: {
                    if (formula[cursor] >= '0' && formula[cursor] <= '9') current_state = NUMERIC;
                    else if (formula[cursor] == ')' || formula[cursor] == '(') current_state = PARENTHESIS;
                    else {
                        alpha_buffer += formula[cursor];
                        if (formula[cursor] >= 'A' && formula[cursor] <= 'Z') {
                            reverse(alpha_buffer.begin(), alpha_buffer.end());
                            atoms_map[alpha_buffer] += strToInt(numeric_buffer) * atoms_count;
                            numeric_buffer.clear();
                            alpha_buffer.clear();
                        }
                        cursor--;
                    }
                    break;
                }
            }
        }
    }

public:
    string countOfAtoms(string formula) {
        map<string, int> atom_count;
        adjustAtoms(formula, 1, atom_count);

        string result;
        for (auto atom: atom_count) {
            result += atom.first;
            if (atom.second > 1) result += to_string(atom.second);
        }

        return result;
    }
};
