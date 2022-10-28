class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        int freq[26];
        int group_index = -1;
        unordered_map<string, int> groups;
        vector<vector<string>> result;

        for (string &str: strs) {
            memset(freq, 0, sizeof(freq));
            for (char &c: str) ++freq[c - 'a'];
            string key = "";
            for (int i = 0; i < 26; ++i)
                if (freq[i]) key += ((char) (i + 'a')) + to_string(freq[i]);
            if (!groups.count(key)) groups[key] = ++group_index;

            int index = groups[key];
            if (index == result.size()) result.emplace_back();
            result[index].emplace_back(str);
        }

        return result;
    }
};
