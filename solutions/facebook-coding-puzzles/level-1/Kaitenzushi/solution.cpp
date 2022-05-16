#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int getMaximumEatenDishCount(int N, vector<int> D, int K) {
        map<int, int> consumptionOrder;
        int totalConsumption = 0;

        for (int dish: D)
            if (consumptionOrder.find(dish) == consumptionOrder.end() ||
                (totalConsumption - consumptionOrder[dish]) >= K) {
                consumptionOrder[dish] = ++totalConsumption;
            }

        return totalConsumption;
}

