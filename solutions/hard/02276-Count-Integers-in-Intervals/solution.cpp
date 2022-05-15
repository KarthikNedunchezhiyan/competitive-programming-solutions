class CountIntervals {
private:
    map<int, int> intervals;
    int totalIntervals = 0;
public:

    CountIntervals() {}

    void add(int left, int right) {
        auto cit = intervals.upper_bound(left);

        if (cit != intervals.begin()) {
            auto p = prev(cit);

            if (p->second >= left) {
                left = p->first;
                right = max(p->second, right);
                totalIntervals -= p->second - p->first + 1;
                intervals.erase(p);
            }
        }

        for (; cit != intervals.end() && right >= cit->first; intervals.erase(cit++)) {
            right = max(right, cit->second);
            totalIntervals -= cit->second - cit->first + 1;
        }

        totalIntervals += right - left + 1;
        intervals[left] = right;
    }

    int count() {
        return totalIntervals;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
