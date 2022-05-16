class DisjointSets {
public:
    vector<int> parent;

    DisjointSets(int size) {
        this->parent.reserve(size);

        for (int i = 0; i < size; i++)
            this->parent.push_back(i);
    }

    int findRoot(int target) {
        if (target == parent[target])
            return target;

        return parent[target] = findRoot(parent[target]);
    }

    void makeUnion(int x, int y) {
        parent[findRoot(x)] = findRoot(y);
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        DisjointSets disjoint_sets = DisjointSets(s.length());

        for (int i = 0; i < pairs.size(); i++)
            disjoint_sets.makeUnion(pairs[i][0], pairs[i][1]);


        string result;
        result.resize(s.length());
        vector<vector<int>> connected_components = vector(s.length(), vector<int>());

        for (int i = 0; i < s.length(); i++) {
            int root = disjoint_sets.findRoot(i);

            connected_components[root].push_back(i);
        }

        for (int i = 0; i < connected_components.size(); i++)
            if (connected_components[i].size() != 0) {
                vector<char> component_chars = vector<char>(connected_components[i].size());
                for (int j = 0; j < connected_components[i].size(); j++) {
                    component_chars[j] = s[connected_components[i][j]];
                }

                sort(component_chars.begin(), component_chars.end(),
                     [](char x, char y) {
                         return x < y;
                     });

                for (int j = 0; j < connected_components[i].size(); j++)
                    result[connected_components[i][j]] = component_chars[j];
            }

        return result;
    }
};
