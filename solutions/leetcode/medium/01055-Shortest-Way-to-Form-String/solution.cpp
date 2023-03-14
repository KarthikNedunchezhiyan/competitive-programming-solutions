class Solution {
    int find(int index, string &target, unordered_map<char, vector<int>> &lookup) {
        int minPickable = 0;
        while (index < target.length()) {
            if (!lookup.count(target[index])) return -1;
            auto it = lower_bound(lookup[target[index]].begin(), lookup[target[index]].end(), minPickable);
            if (it == lookup[target[index]].end()) {
                if (!minPickable) return -1;
                int res = find(index, target, lookup);
                return res != -1 ? res + 1 : -1;
            }
            minPickable = *it + 1;
            ++index;
        }

        return 1;
    }

public:
    int shortestWay(string source, string target) {
        unordered_map<char, vector<int>> lookup;
        for (int i = 0; i < source.length(); ++i) {
            if (lookup.count(source[i])) lookup[source[i]].push_back(i);
            else lookup[source[i]] = {i};
        }
        return find(0, target, lookup);
    }
};
