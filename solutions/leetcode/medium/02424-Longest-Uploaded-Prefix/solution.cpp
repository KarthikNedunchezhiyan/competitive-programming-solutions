class LUPrefix {
public:
    vector<bool> videos;
    int max_prefix = 0;

    LUPrefix(int n) {
        videos = vector<bool>(n + 1, false);
    }

    void upload(int video) {
        videos[video] = true;
    }

    int longest() {
        for (int i = max_prefix + 1; i < videos.size(); ++i)
            if (videos[i]) max_prefix = i; else break;

        return max_prefix;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
