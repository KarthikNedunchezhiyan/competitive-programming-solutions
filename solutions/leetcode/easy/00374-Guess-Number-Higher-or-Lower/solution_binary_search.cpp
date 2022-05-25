/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
private:
    int f(int left, int right) {
        if (left > right)
            return -1;

        int middle = left + ((right - left) / 2);

        int guessDir = guess(middle);

        return !guessDir ? middle : guessDir == -1 ? f(left, middle - 1) : f(middle + 1, right);
    }

public:
    int guessNumber(int n) {
        return f(0, n);
    }
};
