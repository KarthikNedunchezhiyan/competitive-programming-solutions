class Solution {
public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int face_up_cursor = 0, face_down_cursor = tokens.size(), score = 0, score_max = 0;
        while (face_up_cursor < face_down_cursor) {
            if (tokens[face_up_cursor] <= power) {
                power -= tokens[face_up_cursor++];
                score++;
            } else if (score) {
                score--;
                power += tokens[--face_down_cursor];
            } else
                break;
            score_max = max(score, score_max);
        }

        return score_max;
    }
};
