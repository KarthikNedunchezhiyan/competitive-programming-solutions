class CustomStack {
public:
    vector<int> buffer;
    int cursor = 0;

    void push(int val) {
        if (cursor == buffer.size()) {
            buffer.push_back(val);
            ++cursor;
            return;
        }
        buffer[cursor++] = val;
    }

    void pop() { if (cursor > 0) --cursor; }
};

class Solution {
private:
    void recurse(int min_factor, int remaining, CustomStack &buffer, vector<vector<int>> &result) {
        if (remaining == 1) {
            result.emplace_back();
            result.back().reserve(buffer.cursor);
            for (int i = 0; i < buffer.cursor; ++i) result.back().push_back(buffer.buffer[i]);
            return;
        }

        if (min_factor > remaining) return;

        for (int i = min_factor; i <= remaining / 2; ++i) {
            if (remaining % i == 0) {
                buffer.push(i);
                recurse(i, remaining / i, buffer, result);
                buffer.pop();
            }
        }

        buffer.push(remaining);
        recurse(0, 1, buffer, result);
        buffer.pop();
    }

public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> result;
        CustomStack buffer;
        recurse(2, n, buffer, result);
        result.pop_back();
        return result;
    }
};
