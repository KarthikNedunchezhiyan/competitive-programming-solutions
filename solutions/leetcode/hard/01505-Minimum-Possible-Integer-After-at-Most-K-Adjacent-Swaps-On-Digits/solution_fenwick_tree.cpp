class BIT {
    vector<int> buffer;

public:
    BIT(int size) {
        buffer = vector(size + 1, 0);
    }

    void update(int index, int delta) {
        ++index;
        while (index < buffer.size()) {
            buffer[index] += delta;
            index += index & (-index);
        }
    }

    int getShiftDistance(int index) {
        ++index;
        int result = 0;
        while (index > 0) {
            result += buffer[index];
            index -= index & (-index);
        }
        return result;
    }
};

class Solution {
public:
    string minInteger(string num, int k) {
        map<int, queue<int>> digitLookup;
        for (int i = 0; i < num.length(); ++i) digitLookup[num[i] - '0'].emplace(i);

        BIT *bit = new BIT(num.size());
        string result;
        bool found = true;

        while (k > 0 && found) {
            found = false;
            for (auto &entry: digitLookup) {
                if (!entry.second.empty()) {
                    int initial_pos = entry.second.front();
                    int current_pos = initial_pos + bit->getShiftDistance(initial_pos);

                    if (current_pos <= (result.size() + k)) {
                        found = true;
                        k -= current_pos - result.size();
                        num[initial_pos] = '.';
                        bit->update(0, 1);
                        bit->update(initial_pos, -1);
                        result.push_back((char) (entry.first + '0'));
                        entry.second.pop();
                        break;
                    }
                }
            }
        }

        for (char &digit: num) if (digit != '.') result.push_back(digit);

        return result;
    }
};
