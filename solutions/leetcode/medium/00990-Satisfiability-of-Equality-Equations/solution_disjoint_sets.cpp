#define ascii(x) (x - 'a')

int parents[26];

class Solution {
public:
    bool equationsPossible(vector<string> &equations) {
        for (int i = 0; i < 26; ++i) parents[i] = i;

        function<int(int)> findRoot = [&](int target) {
            return parents[target] == target ? target : (parents[target] = findRoot(parents[target]));
        };

        function<void(int, int)> makeUnion = [&](int a, int b) {
            if (findRoot(a) != findRoot(b)) parents[findRoot(a)] = findRoot(b);
        };

        for (string &equation: equations) {
            if (equation[1] != '=') continue;
            makeUnion(ascii(equation[0]), ascii(equation[3]));
        }

        for (string &equation: equations) {
            if (equation[1] != '!') continue;
            if (findRoot(ascii(equation[0])) == findRoot(ascii(equation[3]))) return false;
        }

        return true;
    }
};
