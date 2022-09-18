class CustomStack {
private:
    int *stack, max_size, cursor = 0;

public:
    CustomStack(int maxSize) {
        stack = new int[maxSize];
        max_size = maxSize;
    }

    void push(int x) {
        if (cursor == max_size) return;
        stack[cursor++] = x;
    }

    int pop() {
        if (cursor - 1 < 0) return -1;
        return stack[--cursor];
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(k, cursor); i++) stack[i] += val;
    }
};
