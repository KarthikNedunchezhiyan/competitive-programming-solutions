enum ParseState {
    READ_ALPHABETS = 0,
    READ_NUMERIC = 1,
    READ_PARENTHESIS = 2,
};

class Solution {
public:
    string decodeString(string s) {
        string alpha_buffer;
        int num_buffer = 0;
        int cursor = 0;
        ParseState current_state = READ_ALPHABETS;

        while (cursor < s.length()) {
            switch (current_state) {
                case READ_ALPHABETS: {
                    if (s[cursor] >= 'a' && s[cursor] <= 'z') alpha_buffer += s[cursor++];
                    else current_state = READ_NUMERIC;
                    break;
                }
                case READ_NUMERIC: {
                    if (s[cursor] >= '0' && s[cursor] <= '9') num_buffer = (num_buffer * 10) + (s[cursor++] - '0');
                    else current_state = READ_PARENTHESIS;
                    break;
                }
                case READ_PARENTHESIS: {
                    if (s[cursor] == '[') {
                        string temp = decodeString(s.substr(cursor + 1));
                        while (num_buffer) {
                            alpha_buffer += temp;
                            --num_buffer;
                        }
                        int openParenthesis = 1;
                        while (openParenthesis) {
                            ++cursor;
                            if (s[cursor] == '[') ++openParenthesis;
                            else if (s[cursor] == ']') --openParenthesis;
                        }
                        ++cursor;
                        current_state = READ_ALPHABETS;
                    } else return alpha_buffer;
                    break;
                }
            }
        }

        return alpha_buffer;
    }
};
