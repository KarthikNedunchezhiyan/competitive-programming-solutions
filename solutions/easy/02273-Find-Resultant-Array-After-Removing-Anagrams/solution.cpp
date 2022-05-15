class Solution {
public:
    vector<string> removeAnagrams(vector<string> &words) {
        vector<string> result;
        string prev = "";
        for (string word: words) {
            string wordSorted = word;
            sort(wordSorted.begin(), wordSorted.end());

            if (wordSorted.compare(prev) != 0) {
                prev = wordSorted;
                result.push_back(word);
            }
        }

        return result;
    }
};
