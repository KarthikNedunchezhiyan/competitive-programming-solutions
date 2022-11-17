struct Node {
    Node *children[2] = {};
};

struct PrefixTree {
    Node *head = new Node();

    void insert(bitset<31> &bits) {
        Node *cursor = head;
        int bits_i = bits.size() - 1;

        while (bits_i >= 0) {
            if (!cursor->children[bits[bits_i]]) cursor->children[bits[bits_i]] = new Node();
            cursor = cursor->children[bits[bits_i--]];
        }
    }

    int xorWithBestMatch(bitset<31> &bits) {
        int bit_val = 1 << (bits.size() - 1), result = 0, bits_i = bits.size() - 1;
        Node *cursor = head;
        while (bits_i >= 0) {
            if (cursor->children[!bits[bits_i]]) {
                result += bit_val;
                cursor = cursor->children[!bits[bits_i]];
            } else cursor = cursor->children[bits[bits_i]];
            --bits_i;
            bit_val >>= 1;
        }

        return result;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        PrefixTree *tree = new PrefixTree();
        int result = 0;
        bitset<31> bits = nums[nums.size() - 1];
        tree->insert(bits);

        for (int i = nums.size() - 2; i >= 0; --i) {
            bits = bitset<31>(nums[i]);
            result = max(result, tree->xorWithBestMatch(bits));
            tree->insert(bits);
        }

        return result;
    }
};
