class Solution {
public:
    bool checkIfPangram(string sentence) {
        if (sentence.length() < 26) return false;

        int visited = 0;
        int unique_chars = 26;
        for (char &c: sentence) {
            int mask = 1 << (c - 'a');
            if (!(visited & mask)) {
                visited |= mask;
                if (--unique_chars == 0) return true;
            }
        }
        
        return false;
    }
};
