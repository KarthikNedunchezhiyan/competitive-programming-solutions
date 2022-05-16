#define move(state) result = (result + f(i + 1, state)) % 1000000007

class Solution {
private:
    int n;
    vector<vector<int>> memo;

    int f(int i, int state) {
        if (i == n)
            return state == 0;

        if (memo[i][state] != -1)
            return memo[i][state];

        int result = 0;

        switch (state) {
            case 0:
                move(0); move(1); move(2); move(3);
                break;
            case 1:
                move(2); move(3);
                break;
            case 2:
                move(1); move(3);
                break;
            case 3:
                move(0);
                break;
        }

        return memo[i][state] = result;
    }

public:
    int numTilings(int n) {
        this->n = n;
        this->memo = vector(n, vector(4, -1));
        return f(0, 0);
    }
};
