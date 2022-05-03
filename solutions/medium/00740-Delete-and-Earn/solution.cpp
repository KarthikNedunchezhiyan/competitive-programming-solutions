class Solution {
private:
    map<int, int> freq_memo;
    map<int, int> result_memo;

    int get_freq_or_default(int num) {
        auto freq_memo_it = freq_memo.find(num);
        return freq_memo_it == freq_memo.end() ? 0 : freq_memo_it->second;
    }

    int f(int num) {
        if (num == 0)
            return 0;

        if (num == 1) {
            return get_freq_or_default(1);
        }

        auto result_memo_it = result_memo.find(num);
        if (result_memo_it != result_memo.end()) {
            return result_memo_it->second;
        }

        int gain = get_freq_or_default(num);

        result_memo[num] = max(f(num - 1), gain + f(num - 2));

        return result_memo[num];
    }

public:
    int deleteAndEarn(vector<int> &nums) {
        int max_value = -1;
        // pre population
        for (int num: nums) {
            auto freq_memo_it = freq_memo.find(num);
            if (freq_memo_it != freq_memo.end()) {
                freq_memo_it->second += num;
            } else {
                freq_memo[num] = num;
            }
            max_value = max(num, max_value);
        }

        return f(max_value);
    }
};
