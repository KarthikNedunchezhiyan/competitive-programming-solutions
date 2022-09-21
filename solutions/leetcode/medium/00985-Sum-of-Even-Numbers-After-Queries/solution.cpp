class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries) {
        vector<int> result;
        result.reserve(queries.size());
        int even_sum = 0;
        for (int &num: nums)
            if (num % 2 == 0) even_sum += num;

        for (vector<int> &query: queries) {
            if (nums[query[1]] % 2 == 0)
                even_sum -= nums[query[1]];

            nums[query[1]] += query[0];

            if (nums[query[1]] % 2 == 0)
                even_sum += nums[query[1]];

            result.push_back(even_sum);
        }

        return result;
    }
};
