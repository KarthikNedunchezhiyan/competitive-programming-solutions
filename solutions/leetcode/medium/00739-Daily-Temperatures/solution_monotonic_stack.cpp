class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> monotonic;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!monotonic.empty() && temperatures[monotonic.top()] < temperatures[i]) {
                temperatures[monotonic.top()] = i - monotonic.top();
                monotonic.pop();
            }
            monotonic.push(i);
        }

        while (!monotonic.empty()) {
            temperatures[monotonic.top()] = 0;
            monotonic.pop();
        }

        return temperatures;
    }
};
