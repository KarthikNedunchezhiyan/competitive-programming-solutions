class MyCircularQueue {
private:
    int start = 0, end = 0, max_size, *buffer;
public:
    MyCircularQueue(int k) {
        max_size = k + 1;
        buffer = new int[max_size];
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        buffer[end] = value;
        end = (end + 1) % max_size;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        start = (start + 1) % max_size;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return buffer[start];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return buffer[end == 0 ? max_size - 1 : end - 1];
    }

    bool isEmpty() {
        return start == end;
    }

    bool isFull() {
        return ((end + 1) % max_size) == start;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
