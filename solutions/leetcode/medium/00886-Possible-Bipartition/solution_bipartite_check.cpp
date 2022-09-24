class Solution {
private:
    bool hasCycle(int cursor, bool color, vector<int> *matrix, vector<short> &color_map) {
        if (color_map[cursor] != -1) return color_map[cursor] != color;

        color_map[cursor] = color;

        for (int i = 0; i < matrix[cursor].size(); ++i)
            if (hasCycle(matrix[cursor][i], !color, matrix, color_map)) return true;

        return false;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes) {
        vector<short> color_map(n + 1, -1);
        vector<int> matrix[n + 1];

        for (vector<int> &dislike: dislikes) {
            matrix[dislike[0]].push_back(dislike[1]);
            matrix[dislike[1]].push_back(dislike[0]);
        }

        for (int i = 1; i <= n; ++i)
            if (color_map[i] == -1 && hasCycle(i, true, matrix, color_map)) return false;

        return true;
    }
};
