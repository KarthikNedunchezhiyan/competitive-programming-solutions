class Node {
    int start, end, value = 0;
    Node *left = nullptr, *right = nullptr;

public:
    Node(int start, int end) {
        this->start = start;
        this->end = end;

        if (start == end) return;

        int mid = start + (end - start) / 2;
        this->left = new Node(start, mid);
        this->right = new Node(mid + 1, end);
    }

    void shift(int start, int end) {
        if (this->start > end || this->end < start) return;
        if (this->start >= start && this->end <= end) {
            ++this->value;
            return;
        }
        if (this->left) this->left->shift(start, end);
        if (this->right) this->right->shift(start, end);
    }

    int getShiftDistance(int target) {
        if (this->start == target && this->end == target) return this->value;
        if (this->start > target || this->end < target) return 0;

        return this->value +
               (this->left ? this->left->getShiftDistance(target) : 0) +
               (this->right ? this->right->getShiftDistance(target) : 0);
    }
};

class Solution {
public:
    string minInteger(string num, int k) {
        map<int, queue<int>> lookup;
        Node *tree = new Node(0, num.length() - 1);
        for (int i = 0; i < num.length(); ++i) lookup[num[i] - '0'].push(i);

        string res = "";
        bool found = true;
        while (k > 0 && found) {
            found = false;
            for (auto &entry: lookup) {
                if (!entry.second.empty()) {
                    int shifted_position = entry.second.front() + tree->getShiftDistance(entry.second.front());
                    if ((shifted_position - res.length()) <= k) {
                        found = true;
                        tree->shift(0, entry.second.front());
                        k -= shifted_position - res.length();
                        res += '0' + entry.first;
                        num[entry.second.front()] = '.';
                        entry.second.pop();
                        break;
                    }
                }
            }
        }

        for (char &n: num) if (n != '.') res += n;
        return res;
    }
};
