class Solution {
public:
    int maxIceCream(vector<int> &costs, int coins) {
        std::sort(costs.begin(), costs.end());
        int i = 0;
        for (; i < costs.size(); ++i) if (costs[i] <= coins) coins -= costs[i]; else break;
        return i;
    }
};
