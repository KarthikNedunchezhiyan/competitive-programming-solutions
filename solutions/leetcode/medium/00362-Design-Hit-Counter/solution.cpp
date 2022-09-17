class HitCounter {
private:
    // <timestamp, hits>
    queue<pair<int, int>> timescale;
    int total_hits = 0;

    void cleanUp(int timestamp) {
        timestamp -= 300;
        while (!timescale.empty() && timescale.front().first <= timestamp) {
            total_hits -= timescale.front().second;
            timescale.pop();
        };
    }

public:
    HitCounter() {}

    void hit(int timestamp) {
        total_hits++;
        if (!timescale.empty() && timescale.back().first == timestamp) timescale.back().second += 1;
        else timescale.push({timestamp, 1});
        cleanUp(timestamp);
    }

    int getHits(int timestamp) {
        cleanUp(timestamp);
        return total_hits;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
