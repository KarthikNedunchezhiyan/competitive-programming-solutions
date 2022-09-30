class CustomStack {
private:
    int *stack, *inc_line, max_size, cursor = 0;

public:
    CustomStack(int maxSize) {
        stack = new int[maxSize];
        inc_line = new int[maxSize + 1];
        max_size = maxSize;
    }

    void push(int x) {
        if (cursor == max_size) return;
        inc_line[cursor] = 0;
        stack[cursor++] = x;
    }

    int pop() {
        if (ifEmpty()) return -1;
        --cursor;
        if (!ifEmpty()) inc_line[cursor - 1] += inc_line[cursor];
        return stack[cursor] + inc_line[cursor];
    }

    void increment(int k, int val) {
        if (ifEmpty()) return;
        inc_line[min(cursor - 1, k - 1)] += val;
    }

    bool ifEmpty() {
        return cursor == 0;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
