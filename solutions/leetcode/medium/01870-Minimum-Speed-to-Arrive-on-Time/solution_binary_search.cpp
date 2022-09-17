class Solution {
private:
    double calculate(vector<int> &dist, double &speed) {
        double result = 0;
        for (int i = 0; i < dist.size() - 1; i++) result += ceil(dist[i] / speed);
        result += dist[dist.size() - 1] / speed;

        return result;
    }

    int search(vector<int> &dist, double start, double end, double max_hour) {
        if ((start + 1) == end || start == end)
            return (calculate(dist, start) <= max_hour) ? start : (calculate(dist, end) <= max_hour) ? end : -1;

        double mid = ceil((start + end) / 2);

        return (calculate(dist, mid) > max_hour) ? search(dist, mid, end, max_hour) : search(dist, start, mid,
                                                                                             max_hour);
    }

public:
    int minSpeedOnTime(vector<int> &dist, double hour) {
        return search(dist, 1, 10000007, hour);
    }
};
