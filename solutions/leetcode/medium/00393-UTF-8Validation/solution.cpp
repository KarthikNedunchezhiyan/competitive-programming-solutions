class Solution {
public:
    bool validUtf8(vector<int> &data) {
        int carry = 0;
        for (int &byte: data) {
            if (byte < 128) {
                if (carry) break;
            } else if (carry > 0) {
                if (!(byte >= 128 && byte <= 191 && --carry >= 0)) break;
            } else if (byte >= 192 && byte <= 223)
                carry = 1;
            else if (byte >= 224 && byte <= 239)
                carry = 2;
            else if (byte >= 240 && byte <= 247)
                carry = 3;
            else return false;
        }

        return carry == 0;
    }
};
