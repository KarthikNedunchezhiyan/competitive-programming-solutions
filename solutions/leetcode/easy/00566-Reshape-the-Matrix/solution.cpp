class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
        const int R = mat.size(), C = mat[0].size();
        if ((R == r && C == c) || (R * C != r * c)) return mat;

        int cursor = 0;
        
        vector<vector<int>> reshaped(r);
        for (int i = 0; i < r; ++i) {
            reshaped[i].reserve(c);
            for (int j = 0; j < c; ++j) 
                reshaped[i].push_back(mat[cursor / C][cursor++ % C]);
        }

        return reshaped;
    }
};
