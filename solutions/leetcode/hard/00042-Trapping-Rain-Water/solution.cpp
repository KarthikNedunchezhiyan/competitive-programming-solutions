class Solution {
public:
    int trap(vector<int> &height) {
        int cursorf = 0, blocks = 0, result = 0;

        // forward
        for (int i = 1; i < height.size(); ++i) {
            if (height[cursorf] > height[i]) {
                blocks += height[i];
                continue;
            }
            result += (height[cursorf] * (i - cursorf - 1)) - blocks;
            cursorf = i, blocks = 0;
        }

        int cursorb = height.size() - 1;
        blocks = 0;
        // backward
        for (int i = height.size() - 2; i >= cursorf; --i) {
            if (height[cursorb] > height[i]) {
                blocks += height[i];
                continue;
            }
            result += (height[cursorb] * (cursorb - i - 1)) - blocks;
            cursorb = i, blocks = 0;
        }

        return result;
    }
};
