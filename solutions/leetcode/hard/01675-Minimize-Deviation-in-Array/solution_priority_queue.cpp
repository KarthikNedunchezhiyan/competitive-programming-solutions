class Solution {
public:
    int minimumDeviation(vector<int> &nums) {
        priority_queue<int> pq;
        int min_val = INT_MAX, max_deviation = INT_MAX;
        for (int &num: nums) {
            while (num % 2) num *= 2;
            min_val = min(min_val, num);
            pq.push(num);
        }

        while (true) {
            int max_val = pq.top();
            max_deviation = min(max_deviation, max_val - min_val);
            pq.pop();

            if (max_val % 2) break;

            max_val /= 2;
            min_val = min(min_val, max_val);
            pq.push(max_val);
        }

        return max_deviation;
    }
};
