typedef pair<string, double> rootpair_t;

class DisjointSets {
public:
    map<string, rootpair_t> parent;

    DisjointSets() {}

    rootpair_t findRoot(string target) {
        if (parent[target].first == target)
            return parent[target];

        rootpair_t root_pair = findRoot(parent[target].first);
        root_pair.second *= parent[target].second;
        return parent[target] = root_pair;
    }

    void makeUnion(string a, string b, double weight) {
        rootpair_t root_pair_a = findRoot(a);
        rootpair_t root_pair_b = findRoot(b);

        if (root_pair_a.first != root_pair_b.first)
            parent[root_pair_b.first] = pair(root_pair_a.first, (root_pair_a.second * weight) / root_pair_b.second);
    }
};

class Solution {
public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        DisjointSets dj_set = DisjointSets();

        for (int i = 0; i < equations.size(); i++) {
            if (dj_set.parent.find(equations[i][0]) == dj_set.parent.end())
                dj_set.parent[equations[i][0]] = pair(equations[i][0], 1);
            if (dj_set.parent.find(equations[i][1]) == dj_set.parent.end())
                dj_set.parent[equations[i][1]] = pair(equations[i][1], 1);

            dj_set.makeUnion(equations[i][0], equations[i][1], values[i]);
        }

        vector<double> result;
        result.reserve(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            double answer = -1;

            if (dj_set.parent.find(queries[i][0]) != dj_set.parent.end() &&
                dj_set.parent.find(queries[i][1]) != dj_set.parent.end()) {
                rootpair_t root_pair_a = dj_set.findRoot(queries[i][0]);
                rootpair_t root_pair_b = dj_set.findRoot(queries[i][1]);

                if (root_pair_a.first == root_pair_b.first)
                    answer = root_pair_b.second / root_pair_a.second;
            }

            result.push_back(answer);
        }

        return result;
    }
};
