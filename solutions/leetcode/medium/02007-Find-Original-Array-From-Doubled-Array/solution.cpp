class Solution {
public:
    vector<int> findOriginalArray(vector<int> &changed) {
        if (changed.size() % 2 != 0)
            return {};

        sort(changed.begin(), changed.end(), greater<>());
        queue<int> queue;

        vector<int> result;
        result.reserve(changed.size() / 2);

        for (int &num: changed)
            if (queue.empty() || queue.front() != num) {
                if (num % 2 != 0) return {};
                queue.emplace(num / 2);
            } else {
                result.push_back(queue.front());
                queue.pop();
            }

        if (!queue.empty()) return {};
        return result;
    }
};
