class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> unique = unordered_set(nums.begin(), nums.end());
        return unique.size() != nums.size();
    }
};
