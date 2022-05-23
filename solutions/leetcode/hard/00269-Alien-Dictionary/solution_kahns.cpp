class Solution {
private:
    int mismatchIndex(string &a, string &b) {
        int N = min(a.length(), b.length());
        for (int i = 0; i < N; i++)
            if (a[i] != b[i])
                return i;

        return -1;
    }

public:
    string alienOrder(vector<string> &words) {
        int N = words.size();
        map<char, set<char>> edges;
        map<char, int> inDegree;
        string tpOrder;
        queue<char> tpQ;
        int uniqueChars = 0;

        for (string word: words)
            for (int i = 0; i < word.length(); i++)
                if (edges.find(word[i]) == edges.end()) {
                    edges[word[i]] = {};
                    uniqueChars++;
                    inDegree[word[i]] = 0;
                }

        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++) {
                if ((words[i].size() > words[j].size()) &&
                    words[i].compare(0, words[j].size(), words[j], 0, words[j].size()) == 0)
                    return "";

                int mismatchI = mismatchIndex(words[i], words[j]);
                if (mismatchI == -1) continue;
                
                char ci = words[i][mismatchI], cj = words[j][mismatchI];

                if (!edges[ci].insert(cj).second) continue;

                inDegree[cj]++;
            }

        for (auto inDegreeItem: inDegree)
            if (inDegreeItem.second == 0)
                tpQ.push(inDegreeItem.first);

        while (!tpQ.empty()) {
            char currentNode = tpQ.front();
            tpQ.pop();

            tpOrder.push_back(currentNode);

            for (char edge: edges[currentNode])
                if (--inDegree[edge] == 0)
                    tpQ.push(edge);
        }

        return tpOrder.size() == uniqueChars ? tpOrder : "";
    }
};
