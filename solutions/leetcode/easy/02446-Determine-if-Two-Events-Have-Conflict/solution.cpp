class Solution {
    int cvtTimeToInt(string &time) {
        return (stoi(time.substr(0, 2)) * 60) + stoi(time.substr(3, 2));
    }
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return !(
            cvtTimeToInt(event1[0]) > cvtTimeToInt(event2[1]) ||
            cvtTimeToInt(event1[1]) < cvtTimeToInt(event2[0])
        );
    }
};
