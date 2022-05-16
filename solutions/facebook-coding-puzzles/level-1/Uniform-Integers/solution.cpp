#include <bits/stdc++.h>
using namespace std;
// Write any include statements here

int getUniformIntegerCountInInterval(long long A, long long B) {
        // Write your code here
        // I can bring a mathematical model that computes the answer O(1). Still, I like to approach this in the below way because the approach I have followed also has a time complexity of O(1) and is quick to code in competitive programming.
        vector<long long> quickSearch;
        quickSearch.reserve(108);

        for (int i = 1; i <= 108; i++)
            if (i < 10)
                quickSearch.push_back(i);
            else
                quickSearch.push_back((quickSearch[i - 10] * 10) + (i % 9 == 0 ? 9 : i % 9));

        int result = 0;

        for (auto it = lower_bound(quickSearch.begin(), quickSearch.end(), A); it != quickSearch.end(); it++)
            if (*it <= B) result++;

        return result;
}

