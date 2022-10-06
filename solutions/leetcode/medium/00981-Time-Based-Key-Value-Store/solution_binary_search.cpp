class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> lookup;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        lookup[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto it = lookup.find(key);
        if (it == lookup.end()) return "";

        int start = 0, end = it->second.size() - 1;

        while (start < end) {
            int mid = start + (end - start + 1) / 2;

            if (it->second[mid].first > timestamp) end = mid - 1;
            else start = mid;
        }

        return it->second[start].first <= timestamp ? it->second[start].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
