class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        int ascii = *upper_bound(letters.begin(), letters.end(), target);
        return ascii <= 0 ? letters[0] : (char) ascii;
    }
};
