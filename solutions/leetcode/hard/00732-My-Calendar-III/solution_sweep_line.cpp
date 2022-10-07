class MyCalendarThree {
private:
    map<int, int> timings;

public:
    MyCalendarThree() {}

    int book(int start, int end) {
        timings[start]++;
        timings[end]--;
        int result = 0, overlap_count = 0;
        for (auto &[_, count]: timings) {
            overlap_count += count;
            result = max(result, overlap_count);
        }

        return result;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
