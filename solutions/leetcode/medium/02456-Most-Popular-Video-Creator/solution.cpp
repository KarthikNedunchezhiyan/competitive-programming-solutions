struct Entry {
public:
    long long total_view = 0;
    int max_views = 0;
    string max_view_id = "";
};

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views) {
        unordered_map<string, Entry> entries;
        long long total_view_max = 0;

        for (int i = 0; i < creators.size(); ++i) {
            if (!entries.count(creators[i]))
                entries[creators[i]] = Entry();
            Entry &entry = entries[creators[i]];
            entry.total_view += views[i];
            if (entry.max_views < views[i] ||
                (entry.max_views == views[i] && (entry.max_view_id.empty() || entry.max_view_id > ids[i]))) {
                entry.max_views = views[i];
                entry.max_view_id = ids[i];
            }
            total_view_max = max(total_view_max, entry.total_view);
        }

        vector<vector<string>> result;
        for (auto &entry: entries)
            if (entry.second.total_view == total_view_max)
                result.push_back({entry.first, entry.second.max_view_id});

        return result;
    }
};
