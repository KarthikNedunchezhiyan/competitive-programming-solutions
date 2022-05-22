#define MOD 1000000007

class Solution {
public:
    int sumSubarrayMins(vector<int> &arr) {
        int N = arr.size();
        vector<pair<int, int>> prvNxtSmallIndex = vector(N, make_pair(-1, N));
        stack<int> monotonic;
        monotonic.push(0);

        for (int i = 1; i < arr.size(); i++) {
            while (!monotonic.empty() && arr[monotonic.top()] >= arr[i]) {
                prvNxtSmallIndex[monotonic.top()].second = i;
                monotonic.pop();
            }

            if (!monotonic.empty())
                prvNxtSmallIndex[i].first = monotonic.top();

            monotonic.push(i);
        }

        unsigned int result = 0;

        for (int i = 0; i < prvNxtSmallIndex.size(); i++) {
            unsigned int right = prvNxtSmallIndex[i].second - i;
            unsigned int left = i - prvNxtSmallIndex[i].first;

            result = (result + (right * ((left * arr[i]) % MOD)) % MOD) % MOD;
        }

        return result;
    }
};
