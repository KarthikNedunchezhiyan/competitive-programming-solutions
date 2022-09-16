class Solution {
public:
    string shiftingLetters(string s, vector<int> &shifts) {
        for (int i = 1; i < shifts.size(); i++) shifts[i] = (shifts[i] % 26) + shifts[i - 1];

        for (int i = 0; i < s.length(); i++)
            s[i] = 'a' + (s[i] - 'a' + (i ? (shifts.back() - shifts[i - 1]) : shifts.back())) % 26;

        return s;
    }
};
