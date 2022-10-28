#define MOD 1000000007

class Solution {
    const int primes[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,
                            97, 101};
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        int group_index = -1;
        unordered_map<long, int> groups;
        vector<vector<string>> result;

        for (string &str: strs) {
            long key = 1;
            for (char &c: str) key = (key * primes[c - 'a']) % MOD;
            if (!groups.count(key)) groups[key] = ++group_index;
            int index = groups[key];
            if (index == result.size()) result.emplace_back();
            result[index].emplace_back(str);
        }

        return result;
    }
};
