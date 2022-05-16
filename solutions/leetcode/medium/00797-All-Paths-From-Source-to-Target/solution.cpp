class Solution {
private:
    vector<vector<int>> graph;
    vector<bool> visitTracker;
    vector<int> buffer;
    vector<vector<int>> possiblePaths;
    int destination;

    void f(int cursor) {
        visitTracker[cursor] = true;
        buffer.push_back(cursor);

        if (cursor == destination) {
            vector<int> possiblePath;
            possiblePath.reserve(buffer.size());
            possiblePath.insert(possiblePath.begin(), buffer.begin(), buffer.end());

            possiblePaths.push_back(possiblePath);
        } else
            for (int i: graph[cursor])
                if (!visitTracker[i])
                    f(i);

        visitTracker[cursor] = false;
        buffer.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        this->graph = graph;
        this->destination = graph.size() - 1;
        this->visitTracker = vector(graph.size(), false);

        f(0);

        return possiblePaths;
    }
};
