class Solution {
public:
    bool isOneBitCharacter(vector<int> &bits) {
        int cursor = 0;
        while (cursor < bits.size() - 1) if (bits[cursor++]) cursor++;

        return cursor == (bits.size() - 1);
    }
};
