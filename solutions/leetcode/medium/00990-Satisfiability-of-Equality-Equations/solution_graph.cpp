#define ascii(x) (x - 'a')

bool visited[26];

class Solution {
public:
    bool equationsPossible(vector<string> &equations) {
        vector<unordered_set<short>> graph(26);

        for (string &equation: equations) {
            if (equation[1] != '=') continue;
            graph[ascii(equation[0])].insert(ascii(equation[3]));
            graph[ascii(equation[3])].insert(ascii(equation[0]));
        }

        function<bool(int cursor, int end)> isReachable = [&](int cursor, int end) {
            if (cursor == end) return true;
            if (visited[cursor]) return false;

            visited[cursor] = true;

            for (auto it = graph[cursor].begin(); it != graph[cursor].end(); it++)
                if (isReachable(*it, end)) return true;
            
            return false;
        };

        for (string &equation: equations) {
            if (equation[1] != '!') continue;
            memset(visited, false, sizeof(visited));
            if (isReachable(ascii(equation[0]), ascii(equation[3]))) return false;
        }

        return true;
    }
};
