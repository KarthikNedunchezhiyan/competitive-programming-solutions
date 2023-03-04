class Solution {
public:
    int compress(vector<char> &chars) {
        chars.push_back(chars.back() + 1);

        char prev = chars[0];
        int count = 1, cursor = 0;

        for (int i = 1; i < chars.size(); ++i) {
            if (chars[i] == prev) ++count;
            else {
                chars[cursor++] = prev;
                int temp = cursor;
                if (count > 1) {
                    while (count) {
                        chars[cursor++] = '0' + (count % 10);
                        count /= 10;
                    }
                    reverse(chars.begin() + temp, chars.begin() + cursor);
                }
                prev = chars[i];
                count = 1;
            }
        }

        return cursor;
    }
};
