class Solution {
private:
    unordered_map<int, int> distance_count;

    bool hasCycle(int cursor, int distance, vector<int> *matrix) {
        if (distance_count.count(cursor)) return ((distance - distance_count[cursor]) % 2);

        distance_count[cursor] = distance;

        for (int i = 0; i < matrix[cursor].size(); ++i)
            if (hasCycle(matrix[cursor][i], distance + 1, matrix)) return true;

        return false;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes) {

        vector<int> matrix[n + 1];

        for (vector<int> &dislike: dislikes) {
            matrix[dislike[0]].push_back(dislike[1]);
            matrix[dislike[1]].push_back(dislike[0]);
        }

        for (int i = 1; i <= n; ++i)
            if (!distance_count.count(i) && hasCycle(i, -1, matrix)) return false;

        return true;
    }
};
