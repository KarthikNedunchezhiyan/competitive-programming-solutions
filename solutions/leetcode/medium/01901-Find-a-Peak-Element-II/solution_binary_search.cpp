class Solution {
private:
    int searchMax(int i, vector<vector<int>> &mat) {
        int max_index = 0;
        for (int j = 1; j < mat[0].size(); ++j)
            if (mat[i][j] > mat[i][max_index])
                max_index = j;
        return max_index;
    }

    int getValue(int i, int j, vector<vector<int>> &mat) {
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size())
            return -1;
        return mat[i][j];
    }

public:
    vector<int> findPeakGrid(vector<vector<int>> &mat) {
        int s = 0, e = mat.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            int max_index = searchMax(mid, mat);

            if (mat[mid][max_index] < getValue(mid - 1, max_index, mat)) e = mid - 1;
            else if (mat[mid][max_index] < getValue(mid + 1, max_index, mat)) s = mid + 1;
            else return {mid, max_index};
        }

        return {};
    }
};
