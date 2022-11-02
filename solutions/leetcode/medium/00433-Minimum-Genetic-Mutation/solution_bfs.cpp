class Solution {
public:
    int minMutation(string start, string end, vector<string> &bank) {
        unordered_set<string_view> bank_lookup;
        unordered_set<string> visited;
        vector<char> transitions = {'A', 'C', 'G', 'T'};
        for (string &valid_mutation: bank) bank_lookup.insert(valid_mutation);

        if (!bank_lookup.count(end)) return -1;
        if (start == end) return 0;

        queue<string> bfs;
        bfs.push(start);
        visited.insert(start);

        int distance = 1;

        while (!bfs.empty()) {
            int bfs_size = bfs.size();
            while (bfs_size--) {
                string current = bfs.front();
                bfs.pop();

                for (int i = 0; i < current.size(); ++i) {
                    for (char &t: transitions) {
                        char temp = current[i];
                        current[i] = t;

                        if (!visited.count(current) && bank_lookup.count(current)) {
                            if (current == end) return distance;
                            visited.insert(current);
                            bfs.push(current);
                        }
                        current[i] = temp;
                    }
                }
            }
            ++distance;
        }

        return -1;
    }
};
