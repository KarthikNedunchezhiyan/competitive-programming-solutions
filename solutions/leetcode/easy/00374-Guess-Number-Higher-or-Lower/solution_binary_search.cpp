/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;

        while (l < r) {
            int pivot = l + (r - l) / 2;
            int guess_res = guess(pivot);
            if (!guess_res) return pivot;
            if (guess_res == 1) l = pivot + 1;
            else r = pivot - 1;
        }

        return l;
    }
};
