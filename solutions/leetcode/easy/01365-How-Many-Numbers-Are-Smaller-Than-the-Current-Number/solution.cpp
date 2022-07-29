class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        vector<int> result = nums;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> smallerCount;

        for (int i = 0; i < nums.size(); i++)
            if (!smallerCount.count(nums[i]))
                smallerCount[nums[i]] = i;

        for (int i = 0; i < result.size(); i++)
            result[i] = smallerCount[result[i]];
        
        return result;
    }
};

