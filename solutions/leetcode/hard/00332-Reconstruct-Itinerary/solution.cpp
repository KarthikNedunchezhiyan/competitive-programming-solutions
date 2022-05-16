class Solution {
private:
    map<string, vector<string>> ticketsMap;
    vector<string> buffer = {"JFK"};

    bool f(string boarding) {
        if (ticketsMap[boarding].empty()) {
            for (auto ticket: ticketsMap)
                if (!ticket.second.empty())
                    return false;

            return true;
        }

        for (int i = 0; i < ticketsMap[boarding].size(); i++) {
            string departure = ticketsMap[boarding][i];
            buffer.push_back(departure);
            ticketsMap[boarding].erase(ticketsMap[boarding].begin() + i);
            if (f(departure))
                return true;

            ticketsMap[boarding].insert(ticketsMap[boarding].begin() + i, departure);
            buffer.pop_back();
        }

        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        // creating ticket map for easy access
        for (int i = 0; i < tickets.size(); i++)
            if (ticketsMap.find(tickets[i][0]) == ticketsMap.end())
                ticketsMap[tickets[i][0]] = {tickets[i][1]};
            else
                ticketsMap[tickets[i][0]].push_back(tickets[i][1]);

        // sort the ticket map (as we need lexicographically sorted value)
        for (auto &ticket: ticketsMap)
            sort(ticket.second.begin(), ticket.second.end(), [](string &a, string &b) {
                return a < b;
            });

        // loading the logic
        f("JFK");

        return buffer;
    }
};
