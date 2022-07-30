class SeatManager {
private:
    priority_queue<int, vector<int>, greater<>> pq;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) pq.push(i);
    }

    int reserve() {
        int result = pq.top();
        pq.pop();

        return result;
    }

    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
