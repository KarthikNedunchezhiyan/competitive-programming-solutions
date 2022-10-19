struct Compare {
    bool operator()(pair<int, string_view> &a, pair<int, string_view> &b) {
         return a.first != b.first ? a.first < b.first : a.second < b.second;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string_view, int> freq;
        for (string &word: words) ++freq[word];
        priority_queue<pair<int, string_view>, vector<pair<int, string_view>>, Compare> pq;
        for (auto &f: freq) {
            pq.emplace(-f.second, f.first);
            if (pq.size() > k) pq.pop();
        }

        vector<string> result;
        while (!pq.empty()) {
            result.emplace_back(string(pq.top().second));
            pq.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
