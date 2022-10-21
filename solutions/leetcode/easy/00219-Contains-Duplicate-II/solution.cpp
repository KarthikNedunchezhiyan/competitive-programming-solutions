class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> index_lookup;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = index_lookup.find(nums[i]);
            if (it != index_lookup.end() && abs(it->second - i) <= k) return true;
            index_lookup[nums[i]] = i;
        }

        return false;
    }
};
