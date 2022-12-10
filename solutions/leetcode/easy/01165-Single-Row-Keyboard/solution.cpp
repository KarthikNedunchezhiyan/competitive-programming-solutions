class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int location[26];
        for (int i = 0; i < keyboard.length(); ++i) location[keyboard[i] - 'a'] = i;
        int distance = 0, cursor = keyboard[0];
        for (char &c: word) {
            distance += abs(location[cursor - 'a'] - location[c - 'a']);
            cursor = c;
        }

        return distance;
    }
};
