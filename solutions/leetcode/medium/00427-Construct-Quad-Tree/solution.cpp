/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    Node *construct(vector<vector<int>> &grid, int x, int y, int n) {
        int sum = 0;
        for (int i = x; i < x + n; ++i)
            for (int j = y; j < y + n; ++j) sum += grid[i][j];

        if (sum == 0 || sum == n * n) return new Node(grid[x][y], true);

        int newN = n / 2;
        return new Node(
                grid[x][y],
                false,
                construct(grid, x, y, newN),
                construct(grid, x, y + newN, newN),
                construct(grid, x + newN, y, newN),
                construct(grid, x + newN, y + newN, newN)
        );
    }

public:
    Node *construct(vector<vector<int>> &grid) {
        return construct(grid, 0, 0, grid.size());
    }
};
