#define MAX 1000000000

class MyCalendarThree {
private:
    map<int, int> lazy_lane;
    map<int, int> max_lane;

    int update(int start, int end, int i, int j, int node) {
        // no overlap
        if (end < i || start > j) return lazy_lane[node] + max_lane[node];
        // complete overlap
        if (i >= start && j <= end) return ++lazy_lane[node] + max_lane[node];

        int mid = i + (j - i) / 2;

        max_lane[node] = max(update(start, end, i, mid, (2 * node) + 1),
                             update(start, end, mid + 1, j, (2 * node) + 2));

        return lazy_lane[node] + max_lane[node];
    }

public:
    MyCalendarThree() {}

    int book(int start, int end) {
        return update(start, end - 1, 0, MAX, 0);
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
