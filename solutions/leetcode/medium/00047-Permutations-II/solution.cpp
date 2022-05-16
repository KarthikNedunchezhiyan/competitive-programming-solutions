class Solution {
private:
    map<int, int> frequency;
    vector<vector<int>> result;
    vector<int> buffer;
    int max_size;

    void f() {
        if (buffer.size() == max_size) {
            vector<int> newVec;
            newVec.reserve(max_size);
            newVec.insert(newVec.end(), buffer.begin(), buffer.end());
            return result.push_back(newVec);
        }

        for (auto freq: frequency) {
            if (freq.second == 0)
                continue;

            frequency[freq.first] -= 1;
            buffer.push_back(freq.first);
            f();
            frequency[freq.first] += 1;
            buffer.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        max_size = nums.size();
        for (int i = 0; i < nums.size(); i++)
            if (frequency.find(nums[i]) == frequency.end()) {
                frequency[nums[i]] = 1;
            } else
                frequency[nums[i]] += 1;

        f();

        return result;
    }
};
