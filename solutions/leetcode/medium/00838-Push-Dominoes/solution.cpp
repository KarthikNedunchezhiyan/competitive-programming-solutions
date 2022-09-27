class Solution {
public:
    string pushDominoes(string dominoes) {
        int start = 0;

        for (int i = 0; i < dominoes.length(); ++i) {
            if (dominoes[i] == 'L') {
                if (dominoes[start] == 'R') {
                    const int len = i - start - 1;
                    if (len % 2 != 0) dominoes[i - ((len + 1) / 2)] = '.';
                    fill(dominoes.begin() + i - (len / 2), dominoes.begin() + i, 'L');
                } else
                    fill(dominoes.begin() + start, dominoes.begin() + i, 'L');
                start = i + 1;
            } else if (dominoes[i] == 'R') start = i;
            else if (dominoes[start] == 'R') dominoes[i] = 'R';
        }

        return dominoes;
    }
};
