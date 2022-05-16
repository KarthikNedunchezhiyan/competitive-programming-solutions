class Solution {
private:
    vector<int> jobDifficulty;
    vector<vector<int>> memo;

    int f(int jobs_left, int days_left) {
        if (days_left > jobs_left)
            return INT_MAX;

        if (memo[jobs_left][days_left] != -1)
            return memo[jobs_left][days_left];

        const int total_jobs = jobDifficulty.size();

        int job_start = total_jobs - jobs_left;
        int result = INT_MAX;
        if (days_left == 1)
            result = *max_element(jobDifficulty.begin() + job_start, jobDifficulty.end());
        else {
            int day_difficulty = -1;
            for (int i = job_start; i < total_jobs; i++) {
                day_difficulty = max(day_difficulty, jobDifficulty[i]);
                int next_half_result = f(total_jobs - i - 1, days_left - 1);
                if (next_half_result != INT_MAX)
                    result = min(result, day_difficulty + next_half_result);
            }
        }

        return memo[jobs_left][days_left] = result;
    }

public:
    int minDifficulty(vector<int> &jobDifficulty, int d) {
        this->jobDifficulty = jobDifficulty;
        this->memo = vector(jobDifficulty.size() + 1, vector(d + 1, -1));
        int result = f(jobDifficulty.size(), d);
        return result != INT_MAX ? result : -1;
    }
};
