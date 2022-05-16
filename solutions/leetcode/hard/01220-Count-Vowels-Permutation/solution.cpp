#define move(val) result = (result + f(val, n - 1)) % 1000000007;

class Solution {
private:
    vector<vector<int>> memo;
    
    int f(char prev, int n) {
        if (n == 0)
            return 1;

        int x_axis = prev == 'a' ? 0 : prev == 'e' ? 1 : prev == 'i' ? 2 : prev == 'o' ? 3 : prev == 'u' ? 4 : 5;

        if (x_axis != 5 && memo[x_axis][n] != -1)
            return memo[x_axis][n];

        int result = 0;

        switch (prev) {
            case 'a':
                move('e') move('i') move('u')
                break;
            case 'e':
                move('i') move('a')
                break;
            case 'i':
                move('e') move('o')
                break;
            case 'o':
                move('i')
                break;
            case 'u':
                move('i') move('o')
                break;
            default:
                move('a') move('e') move('i') move('o') move('u')
                break;
        }

        if (x_axis != 5)
            memo[x_axis][n] = result;

        return result;
    }

public:
    int countVowelPermutation(int n) {
        this->memo = vector(5, vector(n + 1, -1));
        return f('x', n);
    }
};
