class Solution {
    int N;

    int shiftAndComputeRank(int shift_i, int shift_j, vector<vector<int>> &img1, vector<vector<int>> &img2) {
        int rank = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j) {
                int img2_i = i + shift_i, img2_j = j + shift_j;
                if (img2_i < 0 || img2_j < 0 || img2_i >= N || img2_j >= N) continue;
                if (img1[i][j] && img2[img2_i][img2_j]) ++rank;
            }

        return rank;
    }

public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2) {
        this->N = img1.size();
        int max_rank = 0;
        for (int i = -N + 1; i < N; ++i)
            for (int j = -N + 1; j < N; ++j)
                max_rank = max(max_rank, shiftAndComputeRank(i, j, img1, img2));

        return max_rank;
    }
};
