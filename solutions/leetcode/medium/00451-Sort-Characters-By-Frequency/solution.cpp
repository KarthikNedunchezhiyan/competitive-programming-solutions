class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> frequency;
        for (int i = 0; i < 10; ++i) frequency.emplace_back(0, '0' + i);
        for (int i = 0; i < 26; ++i) frequency.emplace_back(0, 'A' + i);
        for (int i = 0; i < 26; ++i) frequency.emplace_back(0, 'a' + i);

        for (char &c: s)++frequency[c < 65 ? c - '0' : c < 97 ? (10 + c - 'A') : (36 + c - 'a')].first;

        sort(frequency.begin(), frequency.end(), greater<>());
        string result = "";

        for (auto &entry: frequency) while (entry.first--) result += entry.second;

        return result;
    }
};
