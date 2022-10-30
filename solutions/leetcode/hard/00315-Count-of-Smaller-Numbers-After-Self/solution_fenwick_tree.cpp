#define MIN -10001
#define MAX 10001

class BIT {
    vector<int> buffer;

    int bucketCount(int index) {
        int total = 0;
        for (index = index + 1; index > 0; index -= index & -index) {
            total += buffer[index];
        }
        return total;
    }

public:
    BIT() {
        buffer = vector(MAX + abs(MIN), 0);
    }

    int normalize(int value) {
        return value < 0 ? abs(MIN) - abs(value) : abs(MIN) + value;
    }

    void update(int value) {
        int index = normalize(value);
        for (index = index + 1; index < buffer.size(); index += index & -index) {
            ++buffer[index];
        }
    }

    int query(int value) {
        int index = normalize(value);
        return bucketCount(index);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int> &nums) {
        BIT *bit = new BIT();
        vector<int> result;
        for (int i = nums.size() - 1; i >= 0; --i) {
            result.push_back(bit->query(nums[i] - 1));
            bit->update(nums[i]);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
