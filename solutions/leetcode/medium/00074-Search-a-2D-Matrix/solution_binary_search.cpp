class Solution {
private:
    int search(vector<vector<int>> &matrix, int s, int e, int target, bool v_dir, int possibleR) {
        if (s == e) return s;

        int mid = s + (e - s + 1) / 2;
        return (v_dir ? matrix[mid][0] : matrix[possibleR][mid]) > target ?
               search(matrix, s, mid - 1, target, v_dir, possibleR) : search(matrix, mid, e, target, v_dir, possibleR);
    }

public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        const int possibleR = search(matrix, 0, matrix.size() - 1, target, true, 0);
        const int possibleC = search(matrix, 0, matrix[0].size() - 1, target, false, possibleR);
        return matrix[possibleR][possibleC] == target;
    }
};
