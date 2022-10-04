class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes) {
        unordered_map<int, int> frequency;
        int max_elm = -1;
        for (int &barcode: barcodes) {
            if (++frequency[barcode] > frequency[max_elm])
                max_elm = barcode;
        }
        int cursor = 0;
        while (frequency[max_elm]--) {
            barcodes[cursor] = max_elm;
            cursor += 2;
        }

        for (auto freq: frequency) {
            while (freq.second-- > 0) {
                if (cursor >= barcodes.size()) cursor = 1;
                barcodes[cursor] = freq.first;
                cursor += 2;
            }
        }

        return barcodes;
    }
};
